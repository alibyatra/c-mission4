#ifndef FREQUENCY_H
#define FREQUENCY_H
#define NUM_LETTERS 26

	typedef struct Node Node;

	Node* createNode(char ch);

    Node* addChild(Node *node, char letter);

    void incremental(Node* root);
    
    void freeNode(Node* root);

    int hasChilds(Node* n);

	void freeTree(Node* root);

    void printTree(Node* root, char *str, int j);

	void printTreeReverse(Node* root, char *str, int j);

#endif