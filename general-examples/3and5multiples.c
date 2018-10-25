#include<stdio.h>

int main(void)
{
    int i;
    
    // start with a sum of 0. we add to this sum everytime we find a multiple
    int sum = 0;

    // first loop through every number from 0 to 1000
    for( i=0; i<1000; i++ ){

      // if any of those numbers is divisible by 5 or 3 then add it to the sum
      if( (i%5==0) || (i%3==0) ){
        sum=sum+i;
      }
    
    }

    printf("%d\n",sum);
    return 0;
}
