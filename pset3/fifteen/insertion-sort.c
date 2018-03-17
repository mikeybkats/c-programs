#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int d, i;
static int array[100];

int *makeArray(){
  // makes an array of random numbers
  for(i = 0; i < d; i++){
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

void insertionSort(int array[], int d){
  int unsortedLength = d;
  int sortedLength = 1;
  int location;
  int i, j, k;
  for(i = 1; i < unsortedLength; i++){
    printf("Unsorted length: %i\n", unsortedLength);
    for(j = 0; j < unsortedLength; j++){
      if(array[i] < array[j]){
        // insert the number into the array 
        location = j;
        printf("Location: %i\n", location);
        for( k = sortedLength; k >= location; k--){
          array[k] = array[k - 1];
        }
        printf("Sorted length: %i\n", sortedLength);
        array[location - 1] = array[j];
      }
      sortedLength++;
    }
  }
  for(int i = 0; i < d; i++){
    printf("%i, ", array[i]);
  }
  printf("]\n");
}

int main( int argc, char *argv[] )
{
  d = atoi(argv[1]);
  printf("%i\n", d);
  int *newArray = makeArray();  
  printf("[ ");
  for(int i = 0; i < d; i++){
    printf("%i, ", newArray[i]);
  }
  printf("]\n");
  
  insertionSort(newArray, d);
 }

