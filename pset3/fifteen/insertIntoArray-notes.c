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


// this for loop: loops through the array and adds a duplicate number
// at a new adjacent position 
// then increases the array by one 
  for( i = num; i >= location; i-- ){
    for( int j = 0; j < num; j++){
			printf("%d, ", arr[j]);
    }
    printf("\n"); 
    printf("\n");
    // array index 
    arr[i] = arr[i - 1];
    
    for( int j = 0; j < num; j++){
      printf("%d, ", arr[j]);
    }
   printf("\n");
   printf("\n"); 
  }

  printf("%d\n", arr[4]);

  num++;

	for( int j = 0; j < num; j++){
		printf("%d, ", arr[j]);
	}

  printf("\n");
  
	arr[location - 1] = element;

  for( i = 0; i < num; i++){
    printf("%d, ", arr[i]);
  }
  
  return 0;
}
