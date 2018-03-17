#include <stdio.h>

int main()
{
  int arr[30], element, num, i, location;

  printf("\nEnter no of elements: ");
  scanf("%d", &num); //address of the num.. 

  for(i = 0; i < num; i++){
    scanf("%d", &arr[i]);
  }

  printf("\nEnter element to be inserted: ");
  scanf("%d", &element); 

  printf("\nEnter the location to insert the element: ");
  scanf("%d", &location);


 for( i = num; i >= location; i-- ){
    arr[i] = arr[i - 1];
 }

  num++;
	arr[location - 1] = element;
 
  return 0;
}
