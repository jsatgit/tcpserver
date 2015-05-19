#ifndef _ADDR_H_
#define _ADDR_H_

#include <netinet/in.h>

extern struct sockaddr_in hostaddr;

/* create an address */
int addr_create(); 

/* convert addr struct to string */
int addr_toString(struct sockaddr* src, char* dest);

#endif // _ADDR_H_
