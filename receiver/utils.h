#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>

#define EXIT_ON_FAIL(res, msg)  \
	if (res == -1) {  			\
		perror(msg); 			\
		perror("\n"); 			\
		exit(EXIT_FAILURE); 	\
	}

#define CONT_ON_FAIL(res, msg)  \
	if (res == -1) {  			\
		perror(msg); 			\
		perror("\n"); 			\
		continue;				\
	}

#define PRINT_ON_FAIL(res, msg)  \
	if (res == -1) {  			 \
		perror(msg); 			 \
		perror("\n"); 			 \
	}

// add macro for sock_destroy on res == -1

#endif // _UTILS_H_
