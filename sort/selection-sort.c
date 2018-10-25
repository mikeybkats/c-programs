#define _XOPEN_SOURCE 500
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int array[100];

int *makeArray(int length){
  // makes an array of random numbers
  int i;
  for(i = 0; i < length; i++){
    array[i] = rand() % 50;
  }
  return array;
}

void swap( int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort( int values[], int n )
{
  // the trick is in knowing where the smallest number is not what it is.
  for(int i = 0; i < n-1; i++){
    int smallestIndex = i;
    // find the smallest element index one step ahead of i 
    for(int j = i+1; j < n; j++){
      if( values[j] < values[smallestIndex] ){
        smallestIndex = j;
      }
    }
    swap(&values[smallestIndex], &values[i]);
  }

  printf("Sorted Array: [ ");
  for(int i = 0; i < n; i++){
    printf("%i, ", values[i]);
  }
  printf("]\n");
}

int main( int argc, char *argv[] )
{
  (void)argc;

  if(!argv[1]){
    printf("Usage: enter an argument to determine array size. Program will generate a random array of numbers to sort.\n");
    return 1;
  }
  // d is the length of the random array to create
  int d;
  d = atoi(argv[1]);

  int *newArray = makeArray(d);  

  printf("Unsorted Array: [ ");
  for(int i = 0; i < d; i++){
    printf("%i, ", newArray[i]);
  }
  printf("]\n");
  
  selectionSort(newArray, d);

 }

