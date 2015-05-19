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
		sock_destroy(hostfd);
	}

	return res;
}

int 
addr_toString(struct sockaddr* src, char* dest) 
{
	const char* res;
	struct sockaddr_in* addr;
	addr = (struct sockaddr_in *)src;

	/* check for ipv6 */
	res = inet_ntop(AF_INET, &(addr->sin_addr), dest, INET_ADDRSTRLEN);
	
	return (res == NULL) ? -1 : 0;
}
