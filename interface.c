#include <stdio.h>

#include "interface.h"
#include "list.h"
#include "parser.h"
#include "error.h"
#include "stack.h"
#include "buffer.h"

struct List *interface(char *input){
	struct Buffer B;
	struct Stack S;

	//inizializzazione buffer
	B.string = input;
	B.i = 0;

	//inizializzazione stack
	initStack(&S, 64);

	struct List *head = NULL;

	int error_flag;

	listParser(&B, &S, &error_flag);

	//soluzione temporanea, lancio un generico errore
	if(error_flag == 0){
		for(int j = S.SP - 1; j >= 0; j--) head = push_front(head, S.mem[j]);
		return head;
	}
	else{
		//qui non è necessario distruggere la lista
		//segnalazione errore generico
		printf("Syntax error\n");
		return NULL;
	}

	destroyStack(&S);
}
