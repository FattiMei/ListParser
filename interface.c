#include <stdio.h>

#include "interface.h"
#include "list.h"
#include "parser.h"
#include "error.h"

struct List *interface(char *input){
	char *ptr = input;
	struct List *head = NULL;
	int error_flag = -1;

	head = listParser(&ptr, &error_flag);

	//soluzione temporanea, lancio un generico errore
	ptr = firstNonSpace(ptr);

	if(error_flag == 0){
		//il parsing è avvenuto con successo
		return head;
	}
	else{
		//distruggo la lista perché non serve più
		destroyList(head);

		//segnalazione errore generico
		printf("Syntax error\n");
		return NULL;
	}	
}
