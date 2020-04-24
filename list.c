#include <malloc.h>
#include <stdio.h>

#include "list.h"

struct List *addList(struct List *head, int element){
	struct List *aux,
		    *new;

	//alloca ed inizializza nuovo elemento
	new = (struct List *) malloc(sizeof(struct List));
	new->value = element;
	new->next = NULL;

	//verifica se la lista è vuota
	if(head == NULL) return new;
	else{
		//cerca l'ultimo elemento
		for(aux = head; aux->next != NULL; aux = aux->next);

		//aggiungi all'ultimo elemento "new"
		aux->next = new;

		return head;
	}
}

void destroyList(struct List *head){
	if(head != NULL){
		destroyList(head->next);
		free(head);
	}
}

void printList(struct List *head){
	//la faccio iterativa, non ricorsiva
	struct List *aux;

	if(head == NULL) printf("NULL");
	else{
		for(aux = head; aux != NULL; aux = aux->next){
			printf("%d", aux->value);

			if(aux->next != NULL) printf(", ");
		}
	}

	putchar('\n');
}
