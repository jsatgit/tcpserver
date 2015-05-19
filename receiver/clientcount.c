#include "clientcount.h"

volatile int clients;

void cc_init() 
{
	clients = 0;
}

int cc_inc() 
{
	return __sync_add_and_fetch(&clients, 1);
}

int cc_dec() 
{
	return __sync_add_and_fetch(&clients, -1);
}
