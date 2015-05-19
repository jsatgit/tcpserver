#ifndef _ARG_H_
#define _ARG_H_

#include <netinet/in.h>

extern const char* hostip;
extern in_port_t hostport;

/* process command line arguments from main */
int arg_proc(int argc, char** argv);

#endif // _ARG_H_
