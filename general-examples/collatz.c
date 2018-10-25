#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  // the collatz conjecture - it is always possible to get 
  // back to 1 with the following steps
    // if n is 1 stop
    // otherwise - if n is even, repeat the process on n/2
    // otherwise - if n is odd, repeat this process on 3n+1
  // write a function to calculate how many steps it will take to 
  // get back to 1 if you start from n and recurse.

int collatz(int n, int count)
{
  printf("n: %i count: %i\n", n, count);

  if(n == 1)
  {
    return count; 
  }
  
  if(n%2 == 0)
  {
    count++;
    count = collatz(n/2, count); 
  }
  
  if(n%2 != 0)
  {
    count++;
    count = collatz(3*n+1, count);
  }
  return count;
}

int main(int argc, char *argv[])
{
  (void)argc;
  int count = 0; 
  int newCount = collatz(atoi(argv[1]), count);

  printf("Total steps: %i\n", newCount);
}
