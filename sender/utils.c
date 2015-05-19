#include "utils.h"

void
trim(const char* str) 
{
	char* first;
	first = strchr(str, '\n');
	if (first) {
		*first = NULL;		
	}
}
