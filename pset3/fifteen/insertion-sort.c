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

// insertion sort
// portion the array in two sides sorted and unsorted
// set number aside 
// scan sorted portion of array
// if number is less than any number in 
// the sorted portion of the array 
// insert the number before that number in the array

void insertionSort(int unsArr[], int d){
  // call the first element in the unsArr sorted
  int temp;
  int i; 
  int j;

  //scan through the unsorted portion of the unsArr 
  // i is the unsorted portion of the unsArr
  // d is lenght of unsArr
  for(i = 1; i < d; i++){
    // scan through the sorted part of the unsArr. 
    // j is the sorted portion of the unsArr
    for(j = 0; j < i; j++){
      // check to see if each number is less than any number in the sorted portion of the unsArr.
      if(unsArr[i] < unsArr[j]){
        temp = unsArr[i];
        unsArr[i] = unsArr[j];
        unsArr[j] = temp;
      }
    }
  }

  printf("[");
  for(i = 0; i < d; i++){
    printf("%i, ", unsArr[i]);
  }
  printf("]\n");
}

int main( int argc, char *argv[] )
{
  if(!argv[1]){
    printf("Usage: enter an argument to determine array size. Program will generate a random array of numbers to sort.");
    return 1;
  }
  // d is the length of the random array to create
  int d;
  d = atoi(argv[1]);

  int *newArray = makeArray(d);  
  printf("[ ");
  for(int i = 0; i < d; i++){
    printf("%i, ", newArray[i]);
  }
  printf("]\n");
  
  insertionSort(newArray, d);
 }

