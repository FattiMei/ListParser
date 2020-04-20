#ifndef TOKEN_STRUCTURE_INCLUDED
#define TOKEN_STRUCTURE_INCLUDED

enum t_type{
	end = '\0',

	open_square = '[',
	closed_square = ']',
	comma = ',',

	integer = 256,
	invalid = 257
};

struct Token{
	enum t_type type;
	int value;
	char *position;
};

#endif
