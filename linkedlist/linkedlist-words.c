#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  first create a node struct
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

void append(llnode_t *head, char *data){
  llnode_t *current = head;

  if(head->word == NULL){
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
  current->next->word = strdup(data);
  current->next->next = NULL;
}

int main(int argc, char *argv[])
{
  llnode_t *head = malloc(sizeof(llnode_t));
  head->word = NULL;
  head->next = NULL;

  FILE *text = fopen(argv[1], "r");
  
  char buffer[45];
  
  int textWord = fscanf(text, "%s", buffer); 

  while(textWord != EOF){
    append( head, buffer);
    textWord = fscanf(text, "%s", buffer);
  }

  /*append(head, "cat");*/
  /*append(head, "dog");*/
  /*append(head, "mouse");*/

  print(head);

  free(head);
  fclose(text);
  return(0);
}
