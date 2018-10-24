// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"

FILE *loadedDictionary;
char buf[45];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODONE
    
    for (int dictWord = fscanf(loadedDictionary, "%s", buf); dictWord != EOF; dictWord = fscanf(loadedDictionary, "%s", buf))
    {
        printf("word: %s\n", word);
        if ( strncmp(buf, word, 45) == 0)
        {
            printf("matched word: %s\n", word); 
            return true;
        }
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODONE
    loadedDictionary = fopen(dictionary, "r");
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
      rewind(loadedDictionary);

      for ( int dictWord = fscanf(loadedDictionary, "%s", buf); dictWord != EOF; dictWord = fscanf(loadedDictionary, "%s", buf)){
        printf("count: %ui", count);
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
