#include "bind.h"
#include "sock.h"
#include "addr.h"
#include <sys/socket.h>

struct sockaddr_in hostaddr;

int
bind_with() 
{
	int res;
	res = bind(hostfd, (struct sockaddr *)&hostaddr, sizeof(hostaddr));

	if (res == -1) {
		sock_destroy(hostfd);
	}

	return res;
}
