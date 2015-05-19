#include "msgloop.h"
#include "accept.h"
#include "sock.h"
#include "utils.h"
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_MAX 512 

int hostfd;

void
ml_start(int clientfd, char* clientip) 
{
	char buf[BUF_MAX];
	int res;
	
	while (1) {
		res = recv(clientfd, buf, BUF_MAX, 0);
		
		if (res == -1) {
			perror("Failed to receive message.\n");
		}
		else if (res == 0) {
			break;	
		}

		printf("%s: %s\n", clientip, buf);

		/* clear buffer */
		memset(buf, 0, sizeof(buf));
	}
}
