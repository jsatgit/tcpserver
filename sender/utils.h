#ifndef _UTILS_H_
#define _UTILS_H_

#include <string.h>

#define EXIT_ON_FAIL(res, msg)  \
	if (res == -1) {  			\
		perror(msg); 			\
		perror("\n"); 			\
		exit(EXIT_FAILURE); 	\
	}

void trim(const char* str); 

// add macro for sock_destroy on res == -1

#endif // _UTILS_H_
