#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char asciiChars[] = { '!','\"','#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '\0' };

void print( int lengthOfHash[], int numberOfCharacters ){
  char *hash;
  
  hash = malloc(sizeof(char)*4);

	for (int y = 0; y < sizeof(*lengthOfHash)/sizeof(int); y++ ){
        	printf("%i ", lengthOfHash[y]);
	}
	if( lengthOfHash[0] == 1){
	   	     printf("%c", asciiChars[0]);   
   	}
	for( int i = 1; i <= numberOfCharacters; i++ ){  
		if( lengthOfHash[i] == 1 && asciiChars[i] != '\0' ){  
        //printf("%c", asciiChars[i]);
        strncat(hash, &asciiChars[i], 1);
	   	}
   	}
  printf("%s", hash);
	printf("\n");
}

void comb( int lengthOfHash[], int K, int numberOfCharacters){ 
    if( K == numberOfCharacters){
        lengthOfHash[K] = 0; print(lengthOfHash, numberOfCharacters);
    	return;
    }
    
    lengthOfHash[K] = 0;
    comb(lengthOfHash, K+1, numberOfCharacters);

    lengthOfHash[K] = 1;
    comb(lengthOfHash, K+1, numberOfCharacters);
    
    return;
}   

int main()
{
		//	
    //
    
    int lengthOfHash[1] = {0};  
    int numberOfCharacters = sizeof(asciiChars)/sizeof(char); 
    printf("the size of int numberOfCharacters is: %i\n", numberOfCharacters);
    comb(lengthOfHash, 0, numberOfCharacters);
}

