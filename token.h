#ifndef TOKEN_STRUCT
#define TOKEN_STRUCT

enum t_type{
	comma = ',',
	end = '\0',

	integer = 256,
	invalid = 257
};

struct Token{
	enum t_type type;
	int position,
	    value;
};

#endif
