#ifndef PARSER_PROTOTYPES_INCLUDED
#define PARSER_PROTOTYPES_INCLUDED

#include "list.h"

void spaceParser(char *s, int *i, int *error_flag);
int integerParser(char *s, int *i, int *error_flag);
struct List *listParser(char *s, int *i, int *error_flag);

#endif
