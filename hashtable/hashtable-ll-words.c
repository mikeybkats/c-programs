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

  while(head != NULL){
    printf("Node: %i Data: %s\n", i, head->word);
    int index = hash(head->word);
    printf("Hashtable index = %i\n\n", index);
    head = head->next;
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

  while(current->next != NULL){
    current = current->next;
  }
  
  llnode_t *next = malloc(sizeof(llnode_t));
  current->next = next;

  char *dupWord = strdup(data);
  current->next->word = dupWord;
  current->next->next = NULL;

  free(dupWord);
}

char *toLowerCase(char *word){
  for(int i = 0; word[i]; i++){
    buf[i] = tolower(word[i]);
  }
  return buf;
}

llnode_t *createNode(char *string){
  llnode_t *node = malloc(sizeof(llnode_t)); 
  char *word = strdup(string);

  node->word = word;
  node->next = NULL;

  return node;
}

void destroyNode(llnode_t *node){
  if(node != NULL){
    if(node->word != NULL){
      free(node->word);
    }
  }
  free(node);
}

bool load(const char *path){
  words = fopen(path, "r");

  if(words){
    int word = fscanf(words, "%44[a-zA-Z]%*[^a-zA-Z]", buf); 

    while(word != EOF){
      char *wordString = buf;
      wordString = toLowerCase(wordString);

      int hashValue = hash(wordString);

      llnode_t *node = createNode(wordString);

      if(hashtable[hashValue] != NULL){
        /*printf("A node exists already\n");*/
        append(node, wordString);
        printf("Appending node: %s\nAppending node to hashtable index: %i\n\n", node->word, hashValue);
        free(node);
      } 
      else { 
        /*printf("Node does not exist.\n");*/
        printf("Creating node: %s\nAdding node to hashtable index: %i\n\n", node->word, hashValue);
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
          printf("freeing: %s\n", current->word);
          destroyNode(current);
          current = tmp;
        }
        tmp = current;
        destroyNode(tmp);
      }
    }
    fclose(words);
    return true;
  }
  fclose(words);
  return false;
}

int main(int argc, char *argv[])
{
  (void) argc;

  loaded = load(argv[1]);

  printf("finished loading\n\n");

  if(loaded){
    printf("Printing nodes... \n\n");
    for(int i = 0; i < 100; i++){
      if(hashtable[i] != NULL){
        print(hashtable[i]);
      }
    }
  } else {
    printf("Failed to load\n");
  }

  printf("Unloading... \n\n");
  bool unloaded = unload();

  if(unloaded){
    printf("\nFinished unloading.\n");
  } else {
    printf("\nFailed to unload properly.\n");
  }

  return(0);
}
