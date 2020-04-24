#include <malloc.h>
#include <stdio.h>
#include <ctype.h>

#include "parser.h"

char *firstNonSpace(char *s){
	while(*s != '\0' && *s == ' ') s++;
	return s;
}

struct List *integerParser(char **string){
	char *current;
	struct List *head = NULL;

	int value = 0,
	    sign = 1;

	current = firstNonSpace(*string);

	if(*current == '-'){
		sign = -1;
		current++;
	}
	if(isdigit(*current)){
		do{
			value = value * 10 + *current - '0';
			current++;
		}while(isdigit(*current));

		value *= sign;


		//aggiorna il puntatore alla stringa
		*string = current;

		head = (struct List *) malloc(sizeof(struct List));
		head->next = NULL;
		head->value = value;

	}

	return head;
}

struct List *listParser(char **string){
	struct List *head = NULL;
	char *current = *string;

	head = integerParser(&current);
	if(head != NULL){
		*string = current;

		current = firstNonSpace(current);
		
		if(*current == ','){
			current++;

			head->next = listParser(&current);

			if(head->next == NULL){
				printf("Expected integer after comma\n");

				//segnalazione più accurata dell'errore
			}
		}
	}

	return head;
}
