#include <malloc.h>
#include <stdio.h>
#include <ctype.h>

#include "parser.h"
#include "error.h"

void spaceParser(char *s, int *i, int *error_flag){
	int current = *i;
	while(s[current] != '\0' && s[current] == ' ') current++;

	*i = current;
}

int integerParser(char *s, int *i, int *error_flag){
	int current = *i;

	int value = 0,
	    sign = 1;

	spaceParser(s, &current, error_flag);

	if(s[current] == '-'){
		sign = -1;
		current++;
	}	
	if(isdigit(s[current])){
		do{
			value = value * 10 + s[current] - '0';
			current++;
		}while(isdigit(s[current]));
		
		value *= sign;
			
		//aggiorna il puntatore alla stringa
		*i = current;	
		*error_flag = 0;
	}
	else{
		*error_flag = 1;
		//bisogna trova un modo per segnalare correttamente tutti gli errori
	}

	return value;
}

struct List *listParser(char *s, int *i, int *error_flag){
	struct List *head = NULL, *aux = NULL;

	//stack
	int stack[64];
	int SP = 0;

	//control
	int tmp,
	    success_flag = 0;

	int current = *i;

	do{
		tmp = integerParser(s, &current, error_flag);

		if(*error_flag == 0){
			//aggiorno la posizione del primo carattere non consumato
			*i = current;

			stack[SP++] = tmp;

			if(SP > 63){
				printf("Error: too many items in list\n");
				break;
			}

			spaceParser(s, &current, error_flag);

			if(s[current] == '\0') success_flag = 1;
			else if(s[current] != ',') break;
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
