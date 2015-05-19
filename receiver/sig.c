#include "sig.h"
#include "sock.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static
void 
sig_handler(int signum) 
{
	if (signum == SIGTSTP) {
		sock_destroy(hostfd);

		// destroy all children as well

		printf("Sucessfully quit application\n");
		exit(EXIT_SUCCESS);
	}
}

int 
sig_init() 
{
	struct sigaction act;
	memset(&act, 0, sizeof(act));
	act.sa_handler = sig_handler;

	int res;
	res = sigaction(SIGTSTP, &act, NULL);

	return res;
}
