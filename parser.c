#include <malloc.h>
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>

#include "parser.h"
#include "error.h"
#include "buffer.h"

void spaceParser(struct Buffer *B, int *error_flag){
	int current = B->i;
	while(B->string[current] != '\0' && B->string[current] == ' ') current++;

	B->i = current;
}

int integerParser(struct Buffer *B, int *error_flag){
	int current = B->i;

	int value = 0,
	    sign = 1;

	spaceParser(B, error_flag);

	if(B->string[current] == '-'){
		sign = -1;
		current++;
	}	
	if(isdigit(B->string[current])){
		do{
			value = value * 10 + B->string[current] - '0';
			current++;
		}while(isdigit(B->string[current]));
		
		value *= sign;
			
		//aggiorna il puntatore alla stringa
		B->i = current;	
		*error_flag = 0;
	}
	else{
		*error_flag = 1;

		printf("Error: expected integer at position %d\n", current);
		pointError(B->string, current);
	}

	return value;
}

void listParser(struct Buffer *B, int *stack, int *SP, int *error_flag){
	struct List *head = NULL, *aux = NULL;

	//control
	int tmp,
	    success_flag = 1;

	do{
		tmp = integerParser(B, error_flag);

		if(*error_flag == 0){
			stack[(*SP)++] = tmp;

			if(*SP > 63){
				printf("Error: too many items in list\n");
				*error_flag = 1;
				break;
			}

			spaceParser(B, error_flag);

			if(B->string[B->i] == '\0');
			else if(B->string[B->i] != ','){
				printf("Error: expected comma after integer at position %d\n", B->i);
				pointError(B->string, B->i);

				success_flag = 0;
			}
			else B->i++;
		}
		else success_flag = 0;
	}while(B->string[B->i] != '\0');
}
