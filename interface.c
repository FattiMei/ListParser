#include <stdio.h>

#include "parser.h"
#include "interface.h"
#include "list.h"
#include "error.h"

struct List interface(char *input){
	struct List list;
	initList(&list);

	struct ErrorHandler hnd;
	hnd.string = input;
	hnd.success_flag = 0;

	char *current;

	current = rowParser(input, &list, &hnd);

	printf("(\"%s\", ", current);
	printList(&list);
	printf(")\n");

	return list;
}
