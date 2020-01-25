#include <stdio.h> 
#include <ctype.h>
#include "frequency.h"

int main(int argc, char const *argv[])
{
	char buffer; 
	char choose= 't'; 
	int i=0; 
	int max=0; 
	Node *root= createNode('\0');
	Node *temp = root; 

	while ((buffer=getc(stdin)) != EOF)
	{
		if ((buffer >= 'a' && buffer <= 'z') || (buffer >= 'A' && buffer <= 'Z'))
		{	
			temp = addChild(temp, tolower(buffer));
			i++;
		}
		else if (buffer == ' ' || buffer == '\n' || buffer == '\t')
		{
			incremental(temp); 
			temp = root;
			if (i > max) max = i; 
			i=0;
		}

	}
	
	char cmon[max+2]; 

	if(argc>1){ choose=*argv[1]; } 
	
	if(choose == 'r'){ printTreeReverse(root, cmon, 0); } 

	else{ printTree(root, cmon, 0); } 

	freeTree(root);  

	return 0;
}