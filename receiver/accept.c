#include "accept.h"
#include "sock.h"
#include "utils.h"
#include "service.h"
#include "clientinfo.h"

#include <unistd.h>
#include <sys/socket.h>
#include <pthread.h>

static
int 
accept_from(struct sockaddr* clientaddr)
{
	socklen_t clientlen;
	int clientfd;

	clientfd = accept(hostfd, clientaddr, &clientlen);

	return clientfd; 
}

void
accept_loop()
{
	int clientfd;
	struct sockaddr clientaddr;
	pthread_t pt;
	
	while (1) {
		clientfd = accept_from(&clientaddr);
		CONT_ON_FAIL(clientfd, "Failed to accept.");

		struct client_info ci = {clientfd, &clientaddr};
		pthread_create(&pt, NULL, service_client, (void *)&ci);
	}
}
