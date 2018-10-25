#include <stdio.h>
#include <stdlib.h>

//  first create a node struct
typedef struct llnode {
  int val;
  struct llnode *next; 
} llnode_t;

llnode_t push(llnode_t *head, int new_val){
  llnode_t *new_node = head;

  new_node->val = new_val;
  new_node->next = malloc(sizeof(llnode_t));

  return *new_node;
}

llnode_t *create(int val, llnode_t *next){
  llnode_t *new_node = malloc(sizeof(llnode_t));

  if (new_node == NULL) {
    printf("error creating node");
    exit(0); 
  }

  new_node->val = val;
  new_node->next = next;

  return new_node;
}

void prepend(llnode_t **head, int val ){
  llnode_t *new_node = create( val, *head);
  *head = new_node;
}

void print(llnode_t *head){
  llnode_t *current = head;

  int i = 0;
  while(current->next != NULL){
    printf("Node: %i Data: %d\n", i, current->val);
    current = current->next;
    i++;
  }
}

int main(int argc, char *argv[])
{
  llnode_t *head = NULL;
  
  int nodes;
  printf("number of nodes to add: ");
  scanf("%d", &nodes);

  for(int i = 0; i < nodes; i++){
    prepend( &head, i);
  }

  print(head);

  free(head);
  return(0);
}
