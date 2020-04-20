#include <malloc.h>
#include <ctype.h>

#include "parser.h"
#include "tree.h"

char *firstNonSpace(char *s){
	while(*s != '\0' && *s == ' ') s++;
	return s;
}

struct Node *charParser(char **string, char match){
	struct Node *node = NULL;
	struct Token token;
	char *current;

	current = firstNonSpace(*string);
	
	if(*current == match){
		//inizializza un nuovo nodo
		token.type = match;
		token.value = 0;
		token.position = current;

		//aggiorna il puntatore alla stringa
		*string = current + 1;

		node = allocNode(token);
	}

	return node;
}

struct Node *integerParser(char **string){
	struct Node *node = NULL;
	struct Token token;
	char *current;

	current = firstNonSpace(*string);

	if(isdigit(*current)){
		int value = 0;

		token.position = current;
		do{
			value = value * 10 + *current - '0';
			current++;
		}while(isdigit(*current));

		token.type = integer;
		token.value = value;

		//aggiorna il puntatore alla stringa
		*string = current;

		node = allocNode(token);
	}

	return node;
}

struct Node *listParser(char **string){
	struct Node *node = NULL, *aux = NULL;
	char *current = *string;

	node = integerParser(&current);
	if(node != NULL){
		aux = charParser(&current, ',');

		if(aux != NULL){
			aux->l_branch = node;
			node = aux;

			node->r_branch = listParser(&current);
		}
	}

	return node;
}
