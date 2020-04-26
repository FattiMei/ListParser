#include <malloc.h>
#include <stdio.h>
#include <ctype.h>

#include "parser.h"
#include "error.h"

char *firstNonSpace(char *s){
	while(*s != '\0' && *s == ' ') s++;
	return s;
}

struct List *integerParser(char **string, int *error_flag){
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

		*error_flag = 0;
	}
	else{
		*error_flag = 1;
		//bisogna trova un modo per segnalare correttamente tutti gli errori
	}

	return head;
}

struct List *listParser(char **string, int *error_flag){
	struct List *head = NULL;
	char *current = *string;

	head = integerParser(&current, error_flag);
	if(head != NULL){
		*string = current;

		current = firstNonSpace(current);
		
		if(*current == ','){
			current++;

			head->next = listParser(&current, error_flag);
		}
		else if(*current == '\0') *error_flag = 0;
		else *error_flag = 1;
	}
	else *error_flag = 1;

	return head;
}
