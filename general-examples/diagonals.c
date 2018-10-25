#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    printf("Enter an integer to indicate the number of rows and columns: ");
    scanf("%d",&n);
    int a[n][n];
    int i_total = 0;
    int j_total = 0;
    
    printf("Now enter a matrix of numbers according to the number of rows: \n");
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          scanf("%d",&a[a_i][a_j]);
       }
    }
          
    for( int i = 0; i < n; i++ ){
      for( int j = 0; j < n; j++ ){
        if( j == i ){
           i_total = i_total + a[i][j];
        }
        if( j + i + 1 == n ){
           j_total = j_total + a[i][j];
        }
      }
    }
    
    printf("The total of the first diagonal: %d\n", j_total );
    printf("The total of the second diagonal: %d\n", i_total );
    printf("This is the absolute difference between the sums of the diagonals: %d\n", abs(j_total - i_total));

    return 0;
}

