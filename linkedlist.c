#include <stdlib.h>
#include <stdio.h>

typedef struct llnode {
  int val;
  struct llnode *next;
} node;

// add an item at the beggining of the list
void prepend( node **head, int data){
  node *newNode = malloc(sizeof(node));
  newNode->val = data;
  newNode->next = *head;
  // reset the head to make the newNode the new first item in the list
  *head = newNode;
}

// add an item at the end of the list
void append(node *head, int data){
  // to add an item at the end of the list we have to iterate over all the items starting with the head
  node *current = head;

  // iterate over the list until we come to null and then we are at the end of the list
  while(current->next != NULL){
    current = current->next;
  }

  // when we get to the end of the list 
  current->next = malloc(sizeof(node));
  current->next->val = data;
  current->next->next = NULL;
}

void print_list(node *head) {
  node *current = head;
  while (current != NULL) {
    printf("%d\n", current->val);
    current = current->next;
  }
}

int main(void)
{
  node *head = malloc(sizeof(node));

  head->val = 0;
  head->next = NULL;

  prepend(&head, 1);
  prepend(&head, 2);
  append(head, 10);

  print_list(head);

  free(head);
}
