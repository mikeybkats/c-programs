// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include <ctype.h>

#include "dictionary.h"

FILE *loadedDictionary;
char buf[45];

#define HASHTABLE 100;

typedef struct llnode {
  char *word;
  struct llnode *next; 
} llnode_t;

unsigned long hash(char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        /*printf("int c = %i\n", c); // only to visualize function*/
        hash = ((hash << 5) + hash) + tolower(c);
        /*printf("hash = %lu\n\n", hash); // only to visualize function*/
    }
    return hash % HASHTABLE;
} 

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

    int index = hash(current->word);
    printf("index = %i\n", index);

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
    head->word = strdup(data);
    return;
  }

  while(current->next != NULL){
    current = current->next;
  }
  
  current->next = malloc(sizeof(llnode_t));
  current->next->word = strdup(data);
  current->next->next = NULL;
}


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODONE
    fseek(loadedDictionary, 0, SEEK_SET);
    for (int dictWord = fscanf(loadedDictionary, "%s", buf); dictWord != EOF; dictWord = fscanf(loadedDictionary, "%s", buf))
    {
        if ( strncmp(buf, word, 45) == 0)
        {
            return true;
        }
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    loadedDictionary = fopen(dictionary, "r");

    // assign the word a hash value
    // add the word to the hashtable
      // first check to see if there is a value at that hash index
      // if no value exists
        // create an empty linked list node  
        // add the value to the linked list
      // else add the value to the linked list

    if (loadedDictionary != NULL) {
      return true;
    }

    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODONE
    unsigned int count = 0;

    if(loadedDictionary != NULL){
      fseek(loadedDictionary, 0, SEEK_SET);
      for ( int dictWord = fscanf(loadedDictionary, "%s", buf); dictWord != EOF; dictWord = fscanf(loadedDictionary, "%s", buf)){
        count++;
      }
      return count;
    }
    
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODONE
    int close = fclose(loadedDictionary);

    if( close == 0 ) {
      return true;
    }

    return false;
}
