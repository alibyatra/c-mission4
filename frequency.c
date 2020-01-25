#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include"frequency.h"
#define NUM_LETTERS ((int)26)

typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct Node 
{
char letter;
long unsigned int count;
struct Node* children[NUM_LETTERS];
char exsist[NUM_LETTERS];
boolean isEndOfWord;
}
Node;

Node* createNode(char ch)
{
   Node* n;
   n->letter = ch;
   n->count = 0;
   n->isEndOfWord = FALSE;
   n = (Node*)malloc(sizeof(Node));
   for(int i=0 ; i<NUM_LETTERS ; i++){
       n->exsist[i] = 0;
   }
   return n;
}

Node* addChild(Node *root, char letter)
{
	if(root->exsist[letter-'a'] == 0)
	{
			Node *newNode = createNode(letter);
			root->exsist[letter-'a'] = 1;
			root->children[letter-'a'] = newNode;
			return newNode;
	}
	return (root->children[letter-'a']);
}

void incremental(Node* root)
{
	root->count++;
}

int hasChilds(Node* n)
{
	int i;
	for (i=0; i<NUM_LETTERS; i++)
	{
		if (n->exsist[i]==1) return 1;
	}
	return 0;
}

void freeTree(Node* root)
{
	int i;

	if (root==NULL) return;
	
	if (hasChilds(root)==0)
	{ 
		free(root);
		return;
	}
	else
	{
		for (i=0; i<NUM_LETTERS; i++)
		{
			if (root->exsist[i]==1)
			{
				freeTree(root->children[i]);
			}
		}
		free(root);
	}   
}

void printTree(Node* root, char *str, int j)
{
	if (hasChilds(root)==0)
	{
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
		return;
	}
	if (root->count > 0)
	{
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
	}
	int i;
	for (i=0; i<NUM_LETTERS; i++)
	{
		if (root->exsist[i]==1)
		{
			str[j] = root->children[i]->letter;
			printTree(root->children[i], str, j+1);
		}
	}
}

void printTreeReverse(Node* root, char *str, int j)
{
	if (hasChilds(root)==0)
	{
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
		return;
	}
	if (root->count > 0)
	{
		str[j] = '\0';
		printf("%s\t%ld\n", str, root->count);
	}
	int i;
	for (i=NUM_LETTERS-1; i>=0; i--)
	{
		if (root->exsist[i]==1)
		{
			str[j] = root->children[i]->letter;
			printTreeReverse(root->children[i], str, j+1);
		}
	}
}