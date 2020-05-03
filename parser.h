#ifndef PARSER_PROTOTYPES_INCLUDED
#define PARSER_PROTOTYPES_INCLUDED

#include "list.h"
#include "buffer.h"

void spaceParser(struct Buffer *B, int *error_flag);
int integerParser(struct Buffer *B, int *error_flag);
struct List *listParser(struct Buffer *B, int *error_flag);

#endif
