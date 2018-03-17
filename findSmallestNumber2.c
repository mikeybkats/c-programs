#include <stdio.h>

int select(int arr[], int lengthOfArray, int startPosition)
{
  int smallestNumber = arr[startPosition];
  //int newSmallestNumber;
  int smallestNumberPosition = startPosition;
  int k;

  //printf("Start position: %i number: %i\n", startPosition, arr[startPosition]);
  for ( k = startPosition; k < lengthOfArray; k++ ){  
    //printf("position %i Number %i\n", k, arr[k]);
    if( arr[k] < smallestNumber ){
      smallestNumberPosition = k;
      smallestNumber = arr[k];
    }
  } 
  //printf("%i\n", smallestNumber);
  //printf("smallestNumberPosition %i\n", smallestNumberPosition);
  return smallestNumberPosition;
}



void sort(int values[], int lengthOfArray)
{ 
    //printf("length of array: %i\n\n", lengthOfArray);
    for ( int i = 0;  i < lengthOfArray-1; i++){
        int min = select(values, lengthOfArray, i);
        //printf("smallest number on this pass %i\n", values[min]);
        int tempValue = values[i];
        values[i] = values[min];
        values[min] = tempValue;
    }
    for( int y = 0; y < lengthOfArray; y++){
      printf("%i, ", values[y]);
    }
    printf("\n");
}

int main( void )
{
  int arr[] = { 1, 111, 12, 523, 9, 1, 39, 293, 17};
  int lengthOfArray = sizeof(arr)/sizeof(int);
  for( int y = 0; y < lengthOfArray; y++){
    printf("%i, ", arr[y]);
  }
  printf("\n");
  sort(arr, lengthOfArray);
}
