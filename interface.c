#include <stdio.h>

#include "interface.h"
#include "list.h"
#include "parser.h"
#include "error.h"

struct List *interface(char *input){
	char *ptr = input;
	struct List *head = NULL;

	head = listParser(&ptr);

	//soluzione temporanea, lancio un generico errore
	ptr = firstNonSpace(ptr);

	if(*ptr == '\0' && head != NULL) return head;
	else{
		printf("Sintax error\n");
		return NULL;
	}
}
