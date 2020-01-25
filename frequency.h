#ifndef FREQUENCY_H
#define FREQUENCY_H
#define NUM_LETTERS 26

	typedef struct Node node;

	node* createNode(char ch);

    node* addChild(node *node, char letter);

    void incremental(node* root);
    
    void freeNode(node* root);

    int hasChilds(node* n);

	void freeTree(node* root);

    void printTree(node* root, char *str, int j);

	void printTreeReverse(node* root, char *str, int j);

#endif