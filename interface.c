#include <stdio.h>

#include "interface.h"
#include "list.h"
#include "parser.h"
#include "error.h"
#include "stack.h"
#include "buffer.h"

struct List *interface(char *input){
	struct Buffer B;

	//inizializzazione buffer
	B.string = input;
	B.i = 0;

	struct List *head = NULL;

	int error_flag;

	head = listParser(&B, &error_flag);

	//soluzione temporanea, lancio un generico errore
	if(error_flag == 0){
		//il parsing è avvenuto con successo
		return head;
	}
	else{
		//qui non è necessario distruggere la lista
		//segnalazione errore generico
		printf("Syntax error\n");
		return NULL;
	}
}
