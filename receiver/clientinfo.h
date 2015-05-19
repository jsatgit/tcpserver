#ifndef _CLIENT_INFO_H_
#define _CLIENT_INFO_H_

#include <sys/socket.h>

struct client_info {
	int fd;
	struct sockaddr* addr;
};

#endif // _CLIENT_INFO_H_
