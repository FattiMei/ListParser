#include <stdio.h>

#include "error.h"

void pointError(char *input, unsigned int position){
	printf("%s\n", input);

	for(unsigned int i = 0; i < position; i++) putchar(' ');
	printf("^\n");
}
