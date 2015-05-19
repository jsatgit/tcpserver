#include "conn.h"
#include "sock.h"
#include "addr.h"
#include <sys/socket.h>

int sockfd;
struct sockaddr_in hostaddr;

int
connect_to()
{
	int res;
	
	res = connect(sockfd, (struct sockaddr *)&hostaddr, sizeof(hostaddr));

	if (res == -1) {
		sock_destroy(sockfd);
	}

	return res;
}
