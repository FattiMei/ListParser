#include <stdio.h>
#include <malloc.h>

#include "token.h"
#include "list.h"

void initList(struct List *list){
	list->head = NULL;
	list->last = NULL;
	list->size = 0;
}

void push_front(struct List *list, int element){
	struct Node *new;

	//allocazione nuovo nodo in memoria
	new = (struct Node *) malloc(sizeof(struct Node));
	new->value = element;

	if(list->size == 0) list->last = new;

	new->next = list->head;
	list->head = new;

	//incrementa la dimensione della lista
	(list->size)++;
}

void push_back(struct List *list, int element){
	struct Node *new;

	//allocazione nuovo nodo in memoria
	new = (struct Node *) malloc(sizeof(struct Node));
	new->value = element;
	new->next = NULL;

	if(list->size == 0){
		list->head = new;
		list->last = new;
	}
	else{
		list->last->next = new;
		list->last = new;
	}

	//incrementa la dimensione della lista
	(list->size)++;
}

void destroyList(struct List *list){
	struct Node *aux, *tmp;

	aux = list->head;

	while(aux != NULL){
		tmp = aux->next;

		free(tmp);
		aux = tmp;
	}

	//riinizializzo i valori della lista
	list->size = 0;
	list->head = NULL;
	list->last = NULL;
}

void printList(struct List *list){
	struct Node *aux;

	for(aux = list->head; aux != NULL; aux = aux->next){
		printf("%d", aux->value);
		if(aux->next != NULL) putchar(',');
	}
}
