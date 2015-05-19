#include "service.h"
#include "addr.h"
#include "utils.h"
#include "msgloop.h"
#include "clientcount.h"
#include "response.h"

#include <string.h>

static
void 
service_response(int fd)
{
	/*
	char response[] = "HTTP/1.1 200 OK\n"
	"Content-Type: text/html\n\n"
	"<!DOCTYPE html>\n"
	"<html>\n"
	"<body>Hello Wayne.</body>\n"
	"</html>\n";
	*/
	char* response;
	response = response_create();

	send(fd, response, strlen(response), 0);
}

static
void 
service_entry(struct sockaddr* addr, char* ip)
{
	int res, cc;
	res = addr_toString(addr, ip);
	if (res == -1) {
		perror("Failed to convert address.\n");
	} else {
		printf("Received connection: %s\n", ip);
	}
	cc = cc_inc();
	printf("%d clients connected.\n", cc);
}

static
void
service_exit(char* ip)
{
	int cc;
	printf("%s has exited.\n", ip);
	cc = cc_dec();
	printf("%d clients connected.\n", cc);
}

void* 
service_client(void* arg) 
{
	char clientip[INET_ADDRSTRLEN];
	struct client_info* ci;
	ci = (struct client_info *)arg; 

	service_entry(ci->addr, clientip);

	service_response(ci->fd);
	ml_start(ci->fd, clientip);

	service_exit(clientip);
	
	return NULL;
}
