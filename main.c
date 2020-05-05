#include <stdio.h>
#include <assert.h>

#include "list.h"
#include "token.h"
#include "parser.h"
#include "interface.h"

int main(){
	struct List list;
	char input[32];
	char *current = NULL;
	
	printf("Inserisci input\n");
	scanf("%s", input);

	list = interface(input);

	destroyList(&list);
	return 0;
}
