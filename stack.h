#ifndef STACK_STRUCTURE_INCLUDED
#define STACK_STRUCTURE_INCLUDED

#include <malloc.h>

struct Stack{
	int *mem;
	int SP, size;
};

void initStack(struct Stack *stack, int size);
void destroyStack(struct Stack *stack);

#endif
