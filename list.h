#ifndef LIST_STRUCTURE_INCLUDED
#define LIST_STRUCTURE_INCLUDED

struct List{
	int value;
	struct List *next;
};

struct List *addList(struct List *head, int element);
void destroyList(struct List *head);
void printList(struct List *head);

#endif
