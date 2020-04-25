#include <stdio.h>

#include "scan.h"
#include "parser.h"
#include "error.h"
#include "list.h"
#include "interface.h"

int main(){
	struct List *head;

	char input[64];

	printf("Inserisci input\n");
	stringScan(input, 64);

	head = interface(input);
	printList(head);

	destroyList(head);
	
	return 0;
}
