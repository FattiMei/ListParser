#include <stdio.h>
#include "scan.h"

void stringScan(char *s, int max_len){
	char c;
	int i = 0;

	while((c = getchar()) != 10){
		if(i < max_len - 1){
			s[i] = c;
			i++;
		}
	}

	//add null character to string
	s[i] = '\0';
}

