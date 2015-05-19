#ifndef _ADDR_H_
#define _ADDR_H_

#include <netinet/in.h>

extern struct sockaddr_in hostaddr;

/* create an address */
int addr_create(); 

#endif // _ADDR_H_
