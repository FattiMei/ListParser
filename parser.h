#ifndef PARSER_PROTOTYPES_INCLUDED
#define PARSER_PROTOTYPES_INCLUDED

#include "list.h"
#include "buffer.h"
#include "stack.h"

void spaceParser(struct Buffer *B, int *error_flag);
int integerParser(struct Buffer *B, int *error_flag);
void listParser(struct Buffer *B, struct Stack *S, int *error_flag);

#endif
