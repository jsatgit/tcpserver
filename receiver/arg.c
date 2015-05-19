#include "arg.h"
#include <stdio.h>
#include <stdlib.h>

static
void
arg_usage()
{
	printf("./prog ipaddr portno\n");
}

int 
arg_proc(int argc, char** argv) 
{
	int res;
	res = 0;

	if (argc != 3) {
		arg_usage();
		res = -1;
	}
	else {
		hostip = argv[1];	
		hostport = atoi(argv[2]); 
	}	

	return res;
}

