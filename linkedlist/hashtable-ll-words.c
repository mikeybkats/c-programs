#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HASHTABLE 100;

typedef struct llnode {
  char *word;
  struct llnode *next; 
} llnode_t;

llnode_t push(llnode_t *head, char *new_word){
  llnode_t *new_node = head;

  new_node->word = new_word;
  new_node->next = malloc(sizeof(llnode_t));

  return *new_node;
}

llnode_t *create(char *word, llnode_t *next){
  llnode_t *new_node = malloc(sizeof(llnode_t));

  if (new_node == NULL) {
    printf("error creating node");
    exit(0); 
  }

  new_node->word = word;
  new_node->next = next;

  return new_node;
}

void prepend(llnode_t **head, char *word ){
  llnode_t *new_node = create( word, *head);
  *head = new_node;
}

void print(llnode_t *head){
  llnode_t *current = head;

  int i = 0;
  while(current != NULL){
    printf("Node: %i Data: %s\n", i, current->word);
    current = current->next;
    i++;
  }
}

bool search(llnode_t *head, char *searchWord){
  llnode_t *current = head;

  while(current != NULL){
    if(strncmp(current->word, searchWord, 45) == 0)
    {
      return true;
    }
    current = current->next;
  }

  return false;
}

void append(llnode_t *head, char *data){
  llnode_t *current = head;

  if(head->word == NULL)
  {
    // set data on head to new data if it is the first node
    printf("appending word: %s\n", data);
    head->word = strdup(data);
    return;
  }

  // if current->next is not == to null then the node is not the first node 
  while(current->next != NULL){
    // set current as a copy of the previous node 
    // now there are two of the same in a row
    current = current->next;
  }
  
  // now set the next as a new empty node
  current->next = malloc(sizeof(llnode_t));
  printf("appending word: %s\n", data);
  // we have to duplicate the string because it points back to the original. if we did not duplicate it would
  // copy over the buffer we are inputing (if any)
  current->next->word = strdup(data);
  current->next->next = NULL;
}

unsigned long hash(char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        printf("int c = %i\n", c); // only to visualize function
    
        hash = ((hash << 5) + hash) + tolower(c);
        printf("hash = %lu\n\n", hash); // only to visualize function
    }
    return hash % HASHTABLE;
} 

int main(int argc, char *argv[])
{
  (void) argc;

  llnode_t *head = malloc(sizeof(llnode_t));
  head->word = NULL;
  head->next = NULL;

  FILE *text = fopen(argv[1], "r");
  
  char buffer[45];
  
  int textWord = fscanf(text, "%44[a-zA-Z]%*[^a-zA-Z]", buffer); 

  while(textWord != EOF){
    append( head, buffer);
    textWord = fscanf(text, "%29[a-zA-Z]%*[^a-zA-Z]", buffer);

    int index = hash(buffer);
    printf("index = %i\n", index);

  }

  print(head);

  bool taco = search(head, "taco");

  if(taco){
    printf("You have found a taco!\n");
  } else {
    printf("There is no taco in the text file.\n");
  } 

  free(head);
  fclose(text);
  return(0);
}
