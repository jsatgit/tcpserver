#include "addr.h"
#include "arg.h"
#include "sock.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

const char* hostip;
in_port_t hostport;

int 
addr_create()
{
	int res;
	res = 0;

	memset(&hostaddr, 0, sizeof(hostaddr));
	hostaddr.sin_family = AF_INET;
	hostaddr.sin_port = htons(hostport); 
	res = inet_pton(AF_INET, hostip, &hostaddr.sin_addr);

	res = (res != 1) ? -1 : 0;

	if (res == -1) {
		sock_destroy(sockfd);
	}

	return res;
}
