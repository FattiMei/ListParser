#include <malloc.h>

#include "token.h"
#include "tree.h"

struct Node *allocNode(struct Token token){
	struct Node *new_node;

	new_node = (struct Node *) malloc(sizeof(struct Node));
	if(new_node != NULL){
		new_node->token = token;
		new_node->l_branch = NULL;
		new_node->r_branch = NULL;
	}

	return new_node;
}

void printTree(struct Node *root){
	if(root != NULL){
		if(root->token.type == integer) printf("%d", root->token.value);
		else if(root->token.type == comma){
			printTree(root->l_branch);
			putchar(',');
			printTree(root->r_branch);
		}
	}
	else printf("<!>");
}

void destroyTree(struct Node *root){
	if(root != NULL){
		destroyTree(root->l_branch);
		destroyTree(root->r_branch);
		free(root);
	}
}
