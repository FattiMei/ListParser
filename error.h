#ifndef ERROR_STRUCT
#define ERROR_STRUCT

struct ErrorHandler{
	char *string;
	int success_flag;
};

void pointError(struct ErrorHandler hnd, int position);

#endif
