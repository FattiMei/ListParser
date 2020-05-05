#ifndef PARSER_PROTOTYPES
#define PARSER_PROTOTYPES

#include "list.h"
#include "error.h"

char *spaceParser(char *input, struct ErrorHandler *hnd);
char *charParser(char c, char *input, struct List *list, struct ErrorHandler *hnd);
char *integerParser(char *input, struct List *list, struct ErrorHandler *hnd);
char *listParser(char *input, struct List *list, struct ErrorHandler *hnd);
char *rowParser(char *input, struct List *list, struct ErrorHandler *hnd);

#endif
