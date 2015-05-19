#ifndef _SOCK_H_
#define _SOCK_H_

extern int hostfd;

/* create socket */
int sock_create();

/* destroy socket */
void sock_destroy(int sockfd);

#endif // _SOCK_H_

