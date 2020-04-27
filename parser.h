#ifndef PARSER_PROTOTYPES_INCLUDED
#define PARSER_PROTOTYPES_INCLUDED

#include "list.h"

char *firstNonSpace(char *s);

int integerParser(char **string, int *error_flag);
struct List *listParser(char **string, int *error_flag);

#endif
