#include <stdio.h>

#include "interface.h"
#include "list.h"
#include "parser.h"
#include "error.h"
#include "buffer.h"

struct List *interface(char *input){
	struct Buffer B;

	int stack[64];
	int SP = 0;

	//inizializzazione buffer
	B.string = input;
	B.i = 0;

	struct List *head = NULL;

	int error_flag;

	listParser(&B, stack, &SP, &error_flag);

	//soluzione temporanea, lancio un generico errore
	if(error_flag == 0){
		for(int j = SP - 1; j >= 0; j--) head = push_front(head, stack[j]);
		return head;
	}
	else{
		//qui non è necessario distruggere la lista
		//segnalazione errore generico
		printf("Syntax error\n");
		return NULL;
	}
}
