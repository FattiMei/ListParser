#ifndef PARSER_PROTOTYPES_INCLUDED
#define PARSER_PROTOTYPES_INCLUDED

#include "list.h"

char *firstNonSpace(char *s);

struct List *integerParser(char **string);
struct List *listParser(char **string);

#endif
