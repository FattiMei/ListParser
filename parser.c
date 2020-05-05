#include <ctype.h>
#include <stdio.h>

#include "error.h"
#include "parser.h"
#include "list.h"

char *spaceParser(char *input, struct ErrorHandler *hnd){
	while(*input != '\0' && *input == ' ') input++;
	hnd->success_flag = 1;

	return input;
}

char *charParser(char c, char *input, struct List *list, struct ErrorHandler *hnd){
	if(c != '\0' && *input == c){
		hnd->success_flag = 1;
		return input + 1;
	}
	else{
		hnd->success_flag = 0;
		return input;
	}
}

char *integerParser(char *input, struct List *list, struct ErrorHandler *hnd){
	char *current = NULL;
	int value = 0,
	    sign = 1;

	//verifico la presenza di un eventuale segno meno
	current = charParser('-', input, list, hnd);
	if(current != input){
		sign = -1;
		current++;
	}

	if(isdigit(*current)){
		do{
			value = value * 10 + *current - '0';
			current++;
		}while(isdigit(*current));

		value *= sign;

		//aggiungo l'elemento alla lista
		push_back(list, value);

		//aggiorno il puntatore alla stringa
		input = current;

		//aggiorno gli errori
		hnd->success_flag = 1;
	}
	else{
		hnd->success_flag = 0;

		printf("Error: expected integer at position %d\n", current - hnd->string);
		pointError(*hnd, current - hnd->string);
	}

	return input;
}

char *listParser(char *input, struct List *list, struct ErrorHandler *hnd){
	char *current = input;

	current = spaceParser(current, hnd);

	do{
		current = spaceParser(current, hnd);
		current = integerParser(current, list, hnd);

		if(hnd->success_flag == 1){
			input = current;

			current = spaceParser(current, hnd);

			if(*current == '\0');
			else if(*current == ','){
				current++;
			}
			else break;
		}
	}while(*current != '\0' && hnd->success_flag == 1);

	return input;
}

char *rowParser(char *input, struct List *list, struct ErrorHandler *hnd){
	char *current = input;

	current = spaceParser(current, hnd);
	current = charParser('[', current, list, hnd);

	if(hnd->success_flag == 1){
		current = listParser(current, list, hnd);

		if(hnd->success_flag == 1){
			current = spaceParser(current, hnd);
			current = charParser(']', current, list, hnd);

			input = current;
		}
	}
	else{
		printf("Error: expected '[' at the start of list\n");
		pointError(*hnd, current - hnd->string);
	}

	return input;
}
