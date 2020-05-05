#include <stdio.h>

#include "error.h"

void pointError(struct ErrorHandler hnd, int position){
	printf("%s\n", hnd.string);

	for(int i = 0; i < position; i++) putchar(' ');
	printf("^\n");
}
