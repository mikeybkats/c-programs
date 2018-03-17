#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DIM_MIN 3
#define DIM_MAX 9

int board[DIM_MAX][DIM_MAX];
int d;
int i;
int j;
int k; 

//////// binary search
/*int search(int value, int values[], int n)*/
/*{*/
  /*int lengthOfList = n;*/
  
  /*while ( lengthOfList > 0 ){*/
      /*int i = round(lengthOfList / 2);*/
      /*if( value == values[i] ){*/
         /*return i;*/
      /*}*/
      /*if( i < value){*/
          /*i++;*/
      /*}*/
      /*if( i > value){*/
          /*i--;*/
      /*}*/
      /*lengthOfList--;*/
  /*}*/
  /*return 0;*/
/*}*/

///////// linear search 
int search(int searchValue, int boardValues[], int n){
  for(i = 0; i < n; i++ ){
    if( searchValue == boardValues[i] ){
      return i;
    }
  }
  return n*n*n;
}

void makeGrid(int i){
   for(j = 0; j < d; j++){
      for(k = 0; k < d; k++){
        board[j][k] = i;
        i--;
      }
   }
   board[d-1][d-1] = 0;

   if(d%2==0){
      board[d-1][d-3] = 1;
      board[d-1][d-2] = 2;
   }
  

   for(j = 0; j < d; j++){
     for(k = 0; k < d; k++){
       if( board[j][k] != 0 ){
         printf("%2i ", board[j][k]);
       }
       if( board[j][k] == 0 ){
         printf(" _ ");
       }
     }
     printf("\n");
   }
}

int main(int argc, char *argv[])
{
  d = atoi(argv[1]);
  i = d*d-1;
  makeGrid(i);
  
  printf("What number are you searching for: ");
  int searchInt = get_int();
  int result;
  int lengthOfArray = d; 
  
  for(int y = 0; y < d; y++){ 
    result = search(searchInt, board[y], lengthOfArray);

    if(result >= 0 && result < d*d){
      printf("number location: [%i][%i]\n", y, result);
      break;
    }

    if(y == d-1 && result > d*d){
      printf("the specified number is not in the array\n");
    }
  
  }
}


