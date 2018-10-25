#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int getPosition(char c){
   if (c >= 'a' && c <= 'z') {
      return c - 'a';
   }
   if (c >= 'A' && c <= 'Z') {
     return c - 'A';
   }
   else  {
     return -1;
   }
}

const char *collectPlaintext(char *argv[]){
  static char plaintext[64];
  char *pos;
  printf("plaintext: ");
  fgets(plaintext, sizeof(plaintext), stdin);
  
  if ((pos=strchr(plaintext, '\n')) != NULL)
    *pos = '\0'; 
  if(strcmp(plaintext, "\n") == 0){
    exit(-1);
  }
  return plaintext;
}

int testForCase( int number ){
  int numberValue; 
  if(number >= 65 && number <= 90){numberValue = 65;} 
  if(number >= 97 && number <=122){numberValue = 97;}
  return numberValue;
}

char *encryptText(const char *plaintext, char *cipherText){
  int lengthOfPlaintext = strlen(plaintext);
  int lengthOfCiphertext = strlen(cipherText);
  string encryptedOutput;
  int cipherHelper = 0;
  for (int i = 0; i < lengthOfPlaintext; i++){
    if (plaintext[i] == ' '){
      cipherHelper = cipherHelper - 1;
    }
    int cipherPosition = (cipherHelper % lengthOfCiphertext);
    char cipherLetter = cipherText[cipherPosition];
    int shiftPosition = getPosition(cipherLetter); 
    int plainTextNumber = plaintext[i]; 
    int ifUpperOrLower =  testForCase(plainTextNumber);
    if (plaintext[i] != 32 && plaintext[i] != '\0'){
      char encryptedChar = (getPosition(plainTextNumber)+shiftPosition)%26 + ifUpperOrLower; 
      encryptedOutput[i] = encryptedChar;
    }
    if (plaintext[i] == ' '){
      encryptedOutput[i] = ' ';
    }
    cipherHelper++;
  } 
  return encryptedOutput;
}

int testCharacters(const char *word){
  for (int i=0; i < strlen(word); i++){
    int boolean = isalpha(word[i]); 
    //printf("%c", word[i]);
    if (word[i] == ' '){
      continue;
    }
    if(!boolean){
      printf("error: you may only use alphabetic characters. exiting... \n"); 
      exit(1);
    }
  }
  return 1; 
}

int main(int argc, char *argv[])
{
  if (argc > 2){
    printf("error: too many arguments.\n");
    return 0;
  }
  
  char *cipherText = argv[1];
  testCharacters(cipherText);
  const char *wordToEncrypt = collectPlaintext(argv);
  testCharacters(wordToEncrypt);
  char *encryptedText = encryptText(wordToEncrypt, cipherText);
  printf("ciphertext: %s\n", encryptedText);
}
