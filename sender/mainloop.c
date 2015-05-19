#include "mainloop.h"
#include "sock.h"
#include "utils.h"
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_MAX 512 

void
ml_start() 
{
	char buf[BUF_MAX];
	int res;

	while (1) {
		printf("> ");
		memset(buf, 0, sizeof(buf));
		fgets(buf, BUF_MAX, stdin);
		trim(buf);
		res = send(sockfd, buf, strlen(buf) + 1, 0);
		if (res == -1) {
			printf("Failed to send message.\n");
		}
	}
}
