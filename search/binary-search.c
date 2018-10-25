#include <stdio.h> 

int binarySearch( int array[], int left, int right, int target ){
  // repeat until the the array is of size 0. 
  // if right is greater than or equal to
  if( right >= left ){
    // establish the middle of the array
    int midpoint = left + (right - 1)/2;
    
    // if the target is at the middle then stop and return the midpoint
    if(array[midpoint] == target){
      return midpoint;
    }

    // if the target is less than the middle number
    if(target < array[midpoint]){
      // do another search 
      // search the left side of the array
      // the only change is the right side is now gone
      return binarySearch( array, left, midpoint-1, target);
    }

    // if the target is greater than the middle number 
    // search the right side (midpoint+1) for the target
    return binarySearch( array, midpoint+1, right, target );
  }
  return -1;
}

int main(void)
{
  int numbers[] = { 1, 3, 5, 8, 10, 27, 16 };
  int length = sizeof(numbers)/ sizeof(numbers[0]);

  int result = binarySearch( numbers, 0, length-1, 27);

  (result == -1)? printf("Element is not present in array\n")
                 : printf("Element is present at index %d\n",
                                                   result);

}
