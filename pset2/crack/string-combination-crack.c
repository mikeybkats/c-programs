#include <stdio.h>

void print( int A[], int N){
	for (int y = 0; y < 93; y++ ){
        	printf("%i ", A[y]);
	}
	
	char *B[] = { "!","\"","#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "\\", "]", "^", "_", "`", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "{", "|", "}" };
	if( A[0] == 1){
	   	     printf("%s", B[0]);   
   	}
	for( int i = 1; i <= N; i++ ){  
		if( A[i] == 1 ){  
	      		printf("%s", B[i]);
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
    int A[93] = {0};  
    int N = 93; 
    comb(A, 0, N);
}

