#ifndef LIST_STRUCT
#define LIST_STRUCT

#include "token.h"

struct Node{
	struct Node *next;
	int value;
};

struct List{
	struct Node *head, *last;
	int size;
};

void initList(struct List *list);
void push_front(struct List *list, int element);
void push_back(struct List *list, int element);
void destroyList(struct List *list);
void printList(struct List *list);

#endif
