#ifndef PARSER_PROTOTYPES_INCLUDED
#define PARSER_PROTOTYPES_INCLUDED

#include "tree.h"

char *firstNonSpace(char *s);

struct Node *charParser(char **string, char match);
struct Node *integerParser(char **string);
struct Node *listParser(char **string);

#endif
