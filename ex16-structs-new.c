#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Dog 
{
  int age;
  char name[14];
  char color[10];
  char breed[24];
};

struct Dog edward;

struct Human {
  int age;
  int weight;
  char *name;
  char *eyes;
};

struct Human *Human_create(int age, int weight, char *name, char* eyes)
{
  struct Human *who = malloc(sizeof(struct Human));
  assert(who != NULL);

  who->age = age;
  who->weight = weight;
  who->name = strdup(name);
  //char *strdup(const char *s);
  //The strdup() function returns a pointer to a new string which is a duplicate of the string s. Memory for the new string is obtained with malloc, and can be freed with free.
	who->eyes = strdup(eyes);
	
	return who;
}

void Human_destro(struct Human *who){
}

int main( int argc, char *argv[] )
{
  (void)argc;
  (void)argv;
 
  edward.age = 4;
  strcpy(edward.name, "edward");
  strcpy(edward.color, "black");
  strcpy(edward.breed, "King Charles Terrier");
  printf("Dog name: %s\n", edward.name);

	
  return 0;
}
