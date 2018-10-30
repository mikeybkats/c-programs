#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <ctype.h>

/*#define HASHTABLE 100;*/

/*bool loaded;*/

/*FILE *words;*/
/*char buf[45];*/

typedef struct llnode {
  char *word;
  struct llnode *next; 
} llnode;

/*llnode *hashtable[100];*/

// hash function from http://www.cse.yorku.ca/~oz/hash.html
/*unsigned long hash(char *word)*/
/*{*/
  /*unsigned long hash = 5381;*/
  /*int c;*/
  /*while ((c = *word++))*/
  /*{*/
    /*hash = ((hash << 5) + hash) + tolower(c);*/
  /*}*/
  /*return hash % HASHTABLE;*/
/*} */

/*char *toLowerCase(char *word){*/
  /*for(int i = 0; word[i]; i++){*/
    /*buf[i] = tolower(word[i]);*/
  /*}*/
  /*return buf;*/
/*}*/

/*void append(llnode *head, char *data){*/
  /*llnode *current = head;*/

  /*while(current->next != NULL){*/
    /*current = current->next;*/
  /*}*/
  
  /*llnode *next = malloc(sizeof(llnode));*/
  /*current->next = next;*/

  /*char *dupWord = strdup(data);*/
  /*current->next->word = dupWord;*/
  /*current->next->next = NULL;*/

  /*free(dupWord);*/
/*}*/

/*bool load(const char *path){*/
  /*words = fopen(path, "r");*/

  /*if(words){*/
    /*int word = fscanf(words, "%44[a-zA-Z]%*[^a-zA-Z]", buf); */

    /*while(word != EOF){*/
      /*char *wordString = buf;*/
      /*wordString = toLowerCase(wordString);*/

      /*int hashValue = hash(wordString);*/

      /*llnode *node = createNode(wordString);*/

      /*if(hashtable[hashValue] != NULL){*/
        /*append(node, wordString);*/
      /*} */
      /*else { */
        /*[>printf("Node does not exist.\n");<]*/
        /*[>printf("Creating node: %s\nAdding node to hashtable index: %i\n\n", node->word, hashValue);<]*/
        /*[>hashtable[hashValue] = node;<]*/
      /*}*/

      /*word = fscanf(words, "%29[a-zA-Z]%*[^a-zA-Z]", buf);*/
    /*}*/

    /*return true;*/
  /*}*/

  /*return false;*/
/*}*/

void destroyNode(llnode *node){
  if(node->word != NULL){
    free(node->word);
  }
  if(node != NULL){
    free(node);
  }
}

llnode *createNode(char *string){
  llnode *node = malloc(sizeof(llnode)); 
  char *word = strdup(string);

  node->word = word;
  node->next = NULL;

  return node;
}

int main(int argc, char *argv[])
{
  (void) argc;
  (void) argv;

  llnode *dog = createNode("dog");

  printf("Dog: %s\n", dog->word);

  destroyNode(dog);
}
