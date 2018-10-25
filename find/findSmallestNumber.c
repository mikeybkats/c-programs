#include <stdio.h>

int select(int arr[], int lengthOfArray, int startPosition)
{
  //finds the smallest number in the unsorted part and adds it to 
  //the end of the sorted part 
  int smallestNumber = arr[startPosition];
  int smallestNumberPosition = startPosition;
  int k;

  for ( k = startPosition; k < lengthOfArray; k++ ){  
    if( arr[k] < smallestNumber ){
      smallestNumberPosition = k;
      smallestNumber = arr[k];
    }
  } 
  return smallestNumberPosition;
}

void sort(int values[], int lengthOfArray)
{ 
    for ( int i = 0;  i < lengthOfArray-1; i++){
      int min = select(values, lengthOfArray, i);
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
