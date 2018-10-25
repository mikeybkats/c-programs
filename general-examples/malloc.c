#include <stdio.h>
#include <cs50.h>

int main( int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  int o = get_int("enter an integer: ");
  float stack_array[o];
 
  printf("\nstack array size: %lu\n\n", sizeof(stack_array)/sizeof(float));

  // time to allocate the memory
  float* heap_array = malloc(o * sizeof(float));
 
  for( int i = 0; i < o; i++ ){
    heap_array[i] = i + o;
    printf("Location: %i, Heap array length: %i, Value: %f\n", i, o, heap_array[i]); 
  }

  // time to free the memory
  free(heap_array);

  int m;
  int* a;
  int* b = malloc(sizeof(int));
  a = &m;
  a = b;
  m = 10;
  *b = m + 2;
  printf("*b: %i\n", *b);
}
