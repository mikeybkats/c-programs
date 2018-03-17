#include <stdio.h>
#include <cs50.h>

int main(void)
{
  printf("Name: ");
  string name = get_string();
  // string needs to be defined by cs50 
 
  printf("Hello, %s\n", name);
  // %s is a placeholder for the argument - in this case name 
  // \n makes a line break in the output 
}