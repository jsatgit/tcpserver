#include "listen.h"
#include "sock.h"
#include <sys/socket.h>

int backlog;

int
listen_init() 
{
	int res;
	backlog = 100;
	
	res = listen(hostfd, backlog);

	if (res == -1) {
		sock_destroy(hostfd);
	}

	return res;
}
