#include "sock.h"
#include "utils.h"
#include <sys/socket.h>
#include <unistd.h> 
#include <stdlib.h>

int 
sock_create()
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	return sockfd;
}

void
sock_destroy(int sockfd)
{
	int res;
	res = close(sockfd);
	EXIT_ON_FAIL(res, "Failed to close socket.");
}
