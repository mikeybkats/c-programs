#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int array[100];
int *newArray;

int *makeArray(int length){
  // makes an array of random numbers
  int i;
  for(i = 0; i < length; i++){
    array[i] = rand() % 50;
  }
  return array;
}

void merge(int unsArr[], int left, int middle, int right){
  // the code below is from https://www.geeksforgeeks.org/merge-sort/
  int i, j, k;
  int n1 = middle - left + 1;
  int n2 =  right - middle;

  /* create temiddlep unsArrays */
  int L[n1], R[n2];

  /* Copy data to temiddlep unsArrays L[] and R[] */
  for (i = 0; i < n1; i++)
      L[i] = unsArr[left + i];
  for (j = 0; j < n2; j++)
      R[j] = unsArr[middle + 1+ j];

  /* Merge the temiddlep unsArrays back into unsArr[l..r]*/
  i = 0; // Initial index of first subunsArray
  j = 0; // Initial index of second subunsArray
  k = left; // Initial index of middleerged subunsArray
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      unsArr[k] = L[i];
      i++;
    }
    else
    {
      unsArr[k] = R[j];
      j++;
    }
    k++;
  }

  /* Copy the remiddleaining elemiddleents of L[], if there
     are any */
  while (i < n1)
  {
      unsArr[k] = L[i];
      i++;
      k++;
  }

  /* Copy the remiddleaining elemiddleents of R[], if there
     are any */
  while (j < n2)
  {
      unsArr[k] = R[j];
      j++;
      k++;
  }
}

int sort(int unsArr[], int left, int right){
  if(left < right){
    int middle = left+(right-left)/2;

    // Sort first and second halves
    sort(unsArr, left, middle);
    sort(unsArr, middle+1, right);
    
    merge(unsArr, left, middle, right);
  }

  return *unsArr;
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

  newArray = makeArray(d);  
  printf("Unsorted Array: [ ");
  for(int i = 0; i < d; i++){
    printf("%i, ", newArray[i]);
  }
  printf("]\n");
  
  sort(newArray, 0, d-1);
  printf("Sorted Array: [ ");
  for(int i = 0; i < d; i++){
    printf("%i, ", newArray[i]);
  }
  printf("]\n");
 }

