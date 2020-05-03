#ifndef LIST_STRUCTURE_INCLUDED
#define LIST_STRUCTURE_INCLUDED

struct List{
	int value;
	struct List *next;
};

struct List *push_front(struct List *head, int element);
struct List *push_back(struct List *head, int element);
void destroyList(struct List *head);
void printList(struct List *head);

#endif
