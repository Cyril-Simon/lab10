#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trie
{
  int flag;

  struct Trie *children[26];

}Trie;

void insert(struct Trie **ppTrie, char *word);
int numberOfOccurances(struct Trie *pTrie, char *word);
Trie *deallocateTrie(struct Trie *pTrie);

void insert(struct Trie **ppTrie, char *word)
{
  if (*ppTrie == NULL)
  {
    return;
  }

  int length = strlen(word);

  struct Trie *temp = *ppTrie;

  for(int i; i < length; i++)
  {
    int idx = word[i] - 'a';

    if(temp->children[idx] ==  NULL)
    {
      temp->children[i] = calloc(1, sizeof(Trie));
    }

    temp = temp->children[i];
    
  }

  temp->flag++;
  
}

int numberOfOccurances(struct Trie *pTrie, char *word)
{
  if (pTrie == NULL)
  {
    return 0;
  }

  int length = strlen(word);

  struct Trie *temp = pTrie;

  for(int i; i < length; i++)
  {
    int idx = word[i] - 'a';

    temp = temp->children[i];
    
  }

  return temp->flag;
}
Trie *deallocateTrie(struct Trie *pTrie)
{

  int i = 0;

  for(int i = 0; i < 26; i++)
  {
    if(pTrie->children[i])
    {
      deallocateTrie(pTrie->children[i]);
    }
    
  }

  free(pTrie);

  return NULL;
}

int main(void)
{
      Trie *trie = calloc(1, sizeof(Trie));
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};

      for (int i=0;i<5;i++)
      {
        insert(&trie, pWords[i]);
      }
      
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(trie, pWords[i]));
      }
    trie = deallocateTrie(trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}