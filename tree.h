#ifndef TREE_HEADER_INCLUDED
#define TREE_HEADER_INCLUDED

#include "token.h"

struct Node{
	struct Token token;
	struct Node *l_branch,
		    *r_branch;
};

struct Node *allocNode(struct Token token);

void destroyTree(struct Node *root);
void printTree(struct Node *root);

#endif
