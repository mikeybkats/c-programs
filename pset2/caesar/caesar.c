#include <stdio.h>
#include <cs50.h>
#include <string.h>

int letterPosition(int k){
  int letter;
  letter = (k % 26);
  if (letter == 0){
    letter = 26;
  }
  return letter;
}

int letterShifter(int k, string s){
  for (int i = 0; i < strlen(s); i++){
    int encryptedLetterPosition;
    if(s[i] < 65){
      printf("%c", s[i]);
    }
    if( s[i] >= 65 && s[i] <= 90 ){
      encryptedLetterPosition = ((s[i]-64) + k) % 26; 
      printf("%c", 64 + encryptedLetterPosition);
    }
    if( s[i] >= 97 && s[i] <= 122 ){
      encryptedLetterPosition = ((s[i]-96) + k) % 26;
      printf("%c", 96 + encryptedLetterPosition);
    }
  }
  
  printf("\n");
  return true;
}

int main(int argc, string argv[])
{
  if( argc <= 1 ){
    printf( "error: input missing argument \n" );
    return 1;
  }
  if( argc >= 3){
    printf( "error: input has too many arguments \n" );
    return 1;
  }

  int k = atoi(argv[1]);
  if ( k <= 0 ){
    printf("error: input must be a positive integer\n");
    return 1;
  }
  
  printf("plaintext: ");
  string plainWord = get_string();

  printf("ciphertext: ");
  letterShifter(letterPosition(k), plainWord);
}



