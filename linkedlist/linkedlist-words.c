#include <stdio.h>
#include <stdlib.h>

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
  while(current->next != NULL){
    printf("Node: %i Data: %s\n", i, current->word);
    current = current->next;
    i++;
  }
}

int main(int argc, char *argv[])
{
  llnode_t *head = NULL;

  FILE *text = fopen(argv[1], "r");
  
  /*int nodes;*/
  /*printf("number of  to add: ");*/
  /*scanf("%d", &nodes);*/

  char buffer[45];
  for(int textWord = fscanf(text, "%s", buffer); textWord != EOF; textWord = fscanf(text, "%s", buffer)){
    printf("word: %s\n", buffer);
    prepend( &head, buffer);
  }

  print(head);

  free(head);
  fclose(text);
  return(0);
}
