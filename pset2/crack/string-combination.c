#include <stdio.h>

char *asciiCodes(){
  int x;
  int y;
  int asciiCodeArray[4][93];
  static char a[93];
  for (x = 0; x < 93; x++){
    for (y = 0; y < 3; y++){
      asciiCodeArray[x] = x+33;
      a[x] = (char) asciiCodeArray[x];
    }
  }
  return a;
}

void print( int A[], int N){
	for (int y = 0; y < 4; y++ ){
        	printf("%i ", A[y]);
	}
	
	char *B[] = asciiCodes();
	if( A[0] == 1){
	   	     printf("%c", B[0]);   
   	}
	for( int i = 1; i <= N; i++ ){  
		if( A[i] == 1 ){  
	      		printf("%c", B[i]);
	   	}
   	}
	printf("\n");
}

void comb( int A[], int K, int N){ 
    if( K == N){
        A[K] = 0; print(A, N);
    	return;
    }
    
    A[K] = 0;
    comb( A, K+1, N);

    A[K] = 1;
    comb( A, K+1, N);
    
    return;
}   

int main()
{
    int A[4] = {0};  
    int N = 4; 
    comb(A, 0, N);
}

