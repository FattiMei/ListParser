#include <malloc.h>

#include "stack.h"

void initStack(struct Stack *stack, int size){
	//verifica che le dimensioni siano in un certo range
	if(!(size > 0 && size < 129)) size = 64;

	//alloca spazio in memoria
	stack->mem = (int *) malloc(sizeof(int) * size);

	//inizializza i membri
	stack->size = size;
	stack->SP = 0;
}

void destroyStack(struct Stack *stack){
	free(stack->mem);
}
