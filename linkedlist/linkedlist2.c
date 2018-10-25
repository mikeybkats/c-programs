#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>

typedef struct llnode {
  int val;
  struct llnode *next;
} node;

// add an item at the beggining of the list
// requires the head, and data for the node
// malloc a new node 
// set the data
// set the next to the head (so we're saying that the node which was the head is now going to become the second item in the node list)
// set the new head to the new node
void prepend( node **head, int data){
  node *newNode = malloc(sizeof(node));
  newNode->val = data;
  newNode->next = *head;
  // reset the head to make the newNode the new first item in the list
  *head = newNode;
}

// add an item at the end of the list
// to add an item at the end of the list we have to iterate over all the items starting with the head
// iterate over the list until we come to null and then we are at the end of the list
// when we get to the end of the list 
void append(node *head, int data){
  node *current = head;
  while(current->next != NULL){
    current = current->next;
  }
  current->next = malloc(sizeof(node));
  current->next->val = data;
  current->next->next = NULL;
}

void print_list(node *head) {
  node *current = head;
  while (current != NULL) {
    if(current->val){
      printf("%d\n", current->val);
    }
      current = current->next;
  }
}

int main(void)
{
  node *head = malloc(sizeof(node));
  head->val = 0;
  head->next = NULL;

  /*int getData = true;*/
  /*while( getData == true ){*/
    /*int getNodeData = get_int("Set some node data?: ");*/

    /*prepend(&head, makeNodeWithData);*/
  /*}*/

  append(head, 10);
  prepend(&head, 2);
  prepend(&head, 1);

  print_list(head);

  free(head);
}
