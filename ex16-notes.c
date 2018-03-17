#include <stdio.h>
#include <assert.h>
// assert.h - provides a macro called assert which can be used to verify assumptions made by the program and print a diagnostic message if this assumption is false.
#include <stdlib.h>
// stdlib.h - provides library functions, macros and variables - includes the all important malloc() function 
// https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm
#include <string.h>


struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
  struct Person *who = malloc(sizeof(struct Person));
  // malloc will allocate all the space needed for the data types above

  assert(who != NULL);
  // assert checks to make sure that malloc does not return a NULL invalid pointer when a new person is created.
  // a null invalid pointer will make your program crash.

  // void assert(int expression)
  // This is actually a macro and not a function, which can be used to add diagnostics in your C program.

  who->name = strdup(name); //strdup() function returns a pointer to a new string which is a duplicate of the string s 
  // the reason we have to use strdup() here is because the string is of an unknown length?
  who->age = age;
  who->height = height;
  who->weight = weight;
  // this x->y syntax looks a bit strange, but actually means: 
  // (go to this place)–>(and get me) 
  // who->name - gets the member name from the struct who

  return who;
}

void Person_destroy(struct Person *who){
  assert(who != NULL);
  free(who->name);
  free(who);
}

void Person_print(struct Person *who){
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main( int argc, char *argv[] )
{
  (void)argc;
  (void)argv;
  // make two people structures
  struct Person *joe = Person_create( "Joe Alex", 32, 64, 140 );
  struct Person *frank = Person_create( "Frank Blank", 20, 72, 180 );
  
  // print them out and where they were in memory
  printf("Joe is at memory location %p:\n", joe );
  Person_print(joe);
  
  printf("Frank is at memory location %p:\n", frank );
  Person_print(frank);

  // make everyone 20 years of age and then print them again 
  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print( joe );
 
  frank->age += 20;
  frank->weight -= 20;
  Person_print( frank );

  // destroy them both so we clean up 
  Person_destroy( joe );
  Person_destroy( frank );
  
  return 0;
}
