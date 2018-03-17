#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <unistd.h>

char *arrayOfAsciiLetters;

char *asciiCode(){
// create a char *  array of every ascii charracter
  int x;
  int asciiCodeArray[93];
  static char letters[93];
  for ( x = 0; x < 93; x++ ){
    asciiCodeArray[x] = x+33;
    letters[x] = (char) asciiCodeArray[x];
  }
  return letters;
}

char *encryptString( char *original ){
    char saltKey[] = "50";
    string encryptedString = crypt( original, saltKey);
    return encryptedString;
}

void match(int A[], int N){
	for (int y = 0; y < 93; y++ ){
        	printf("%i ", A[y]);
	}

	if(A[0] == 1){
	   	     printf("%s", arrayOfAsciiLetters[0]);   
  }

	for(int i = 1; i <= N; i++){  
		if( A[i] == 1 ){  
        //printf("%s", B[i]);
        char *checkHash = crypt(arrayOfAsciiLetters[i], saltKey);
        if ( argv[1] == checkHash){
          return checkHash; 
        }
	   	}
   	}
	printf("\n");
}

void comb( int A[], int K, int N){ 
    if( K == N){
        A[K] = 0; match(A, N);
    	return;
    }
    
    A[K] = 0;
    comb( A, K+1, N);

    A[K] = 1;
    comb( A, K+1, N);
    
    return;
}   

int main(int argc, char *argv[])
{
  if (argc == 1){
    return printf("no argument present. exiting...\n");
  }

  char saltKey[] = "50";
  char *encryptedString = crypt(argv[1], saltKey);
  // printf("%s\n", encryptedString);
  
  char *arrayOfAsciiLetters = asciiCode();
 
  // the number of combinations 
  int sizeOfArgV = sizeof(argv[1])/sizeof(int);
  int A[sizeOfArgV] = {0};  
  // the number of ascii characters
  int N = 93; 

  comb(A, 0, N);

  //for (int i = 0; i < 93; i++){  
    //printf("%c", arrayOfAsciiLetters[i]);
  //}

  // make a new function( firstParameter is encryptedString, second parameter is arrayOfAsciiLetters)
  // checkIfMatch( encryptedString, arrayOfAsciiLetters ){
  //   
  //
  // }

  printf("\n");
}

