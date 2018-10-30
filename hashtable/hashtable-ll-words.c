#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <ctype.h>

#define HASHTABLE 100;

bool loaded;

FILE *words;
char buf[45];

typedef struct llnode {
  char *word;
  struct llnode *next; 
} llnode_t;

llnode_t *hashtable[100];

// hash function from http://www.cse.yorku.ca/~oz/hash.html
unsigned long hash(char *word)
{
  unsigned long hash = 5381;
  int c;
  while ((c = *word++))
  {
    hash = ((hash << 5) + hash) + tolower(c);
  }
  return hash % HASHTABLE;
} 

void print(llnode_t *head){
  int i = 0;
  llnode_t *current = head;

  while(current != NULL){
    printf("Node: %i Data: %s\n", i, current->word);
    int index = hash(current->word);
    printf("Hashtable index = %i\n\n", index);
    current = current->next;
    i++;
  }
}

void print_list(llnode_t *head) {
  llnode_t *current = head;
  while (current != NULL) {
    if(current->word){
      printf("%s\n", current->word);
    }
      current = current->next;
  }
}

bool search(llnode_t *head, char *searchWord){
  llnode_t *current = head;

  while(current != NULL){
    /*printf("current: %s  searchWord: %s\n", current->word, searchWord);*/
    /*printf("%i\n", strcmp(current->word, searchWord));*/
    int compare = strcmp(current->word, searchWord);
    if(compare == 0)
    {
      /*printf("returning true!\n");*/
      return true;
    }
    current = current->next;
  }

  return false;
}

void append(llnode_t *head, char *data){
  llnode_t *current = head;

  printf("appending: %s, ", data);

  while(current->next != NULL){
    current = current->next;
  }

  char *dupWord = data;
  current->next = malloc(sizeof(llnode_t));
  current->next->word = dupWord;
  current->next->next = NULL;
}

char *toLowerCase(char *word){
  for(int i = 0; word[i]; i++){
    buf[i] = tolower(word[i]);
  }
  return buf;
}

bool load(const char *path){
  words = fopen(path, "r");

  if(words){
    int word = fscanf(words, "%44[a-zA-Z]%*[^a-zA-Z]", buf); 

    while(word != EOF){
      char *wordString = buf;
      wordString = toLowerCase(wordString);

      wordString = strdup(wordString);

      int hashValue = hash(wordString);

      if(hashtable[hashValue] != NULL){
        /*printf("A node exists already\n");*/
        append(hashtable[hashValue], wordString);
        /*printf("Adding node: %s\nAdding node to hashtable index: %i\n\n", node->word, hashValue);*/
      } 
      else { 
        llnode_t *node = malloc(sizeof(llnode_t));
        node->word = wordString;
        node->next = NULL;
        /*printf("Node does not exist.\n");*/
        printf("Adding: %s, ", node->word);
        hashtable[hashValue] = node;
      }
      
      word = fscanf(words, "%29[a-zA-Z]%*[^a-zA-Z]", buf);
    }

    return true;
  }

  return false;
}

bool unload(){
  if(loaded){
    llnode_t *tmp;
    llnode_t *current;

    for(int i = 0; i < 100; i++){
      if(hashtable[i] != NULL){
        current = hashtable[i];
        while(current != NULL){
          tmp = current->next;
          /*printf("freeing: %s\n", current->word);*/
          free(current->word);
          free(current);
          current = tmp;
        }
        tmp = current;
      }
    }
    return true;
  }
  return false;
}

int main(int argc, char *argv[])
{
  (void) argc;

  loaded = load(argv[1]);

  printf("finished loading\n\n");

  if(loaded){
    /*printf("Printing nodes... \n\n");*/
    /*for(int i = 0; i < 100; i++){*/
      /*if(hashtable[i] != NULL){*/
        /*print_list(hashtable[i]);*/
      /*}*/
    /*}*/
  } else {
    printf("Failed to load\n");
  }
  if(argv[2] != NULL){
    char *searchWord = argv[2];

    printf("Does search word %s exist?\n", searchWord);

    bool exists = false;
    int searchHash = hash(searchWord);

    if(hashtable[searchHash] != NULL){
      exists = search(hashtable[searchHash], searchWord);
    }

    if(exists == true){
      printf("The search word %s has been found!\n", searchWord);
    } else {
      printf("The word does not exist in the source file\n");
    }
  }


  printf("Unloading... \n");
  bool unloaded = unload();

  if(unloaded){
    printf("\nFinished unloading.\n");
  } else {
    printf("\nFailed to unload properly.\n");
  }

  return(0);
}
