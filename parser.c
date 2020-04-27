#include <malloc.h>
#include <stdio.h>
#include <ctype.h>

#include "parser.h"
#include "error.h"

char *firstNonSpace(char *s){
	while(*s != '\0' && *s == ' ') s++;
	return s;
}

int integerParser(char **string, int *error_flag){
	char *current;

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
			
		*error_flag = 0;
	}
	else{
		*error_flag = 1;
		//bisogna trova un modo per segnalare correttamente tutti gli errori
	}

	return value;
}

struct List *listParser(char **string, int *error_flag){
	struct List *head = NULL, *aux = NULL;

	//stack
	int stack[64];
	int SP = 0;

	//control
	int tmp,
	    success_flag = 0;

	char *current = *string;

	do{
		tmp = integerParser(&current, error_flag);


		if(*error_flag == 0){
			stack[SP++] = tmp;

			if(SP > 63){
				printf("Error: too many items in list\n");
				break;
			}

			current = firstNonSpace(current);
			if(*current == '\0') success_flag = 1;
			else if(*current != ',') break;
			else current++;
		}
		else break;
	}while(success_flag == 0);

	if(success_flag){
		for(--SP; SP >= 0; SP--){
			head = (struct List *) malloc(sizeof(struct List));
			head->next = aux;
			head->value = stack[SP];

			head->next = aux;
			aux = head;
		}
	}
	return head;
}
