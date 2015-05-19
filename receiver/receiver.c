#include "utils.h"
#include "sig.h"
#include "arg.h"
#include "sock.h"
#include "addr.h"
#include "bind.h"
#include "listen.h"
#include "accept.h"
#include "clientcount.h"
#include "msgloop.h"

int main(int argc, char** argv) {
	int res;

	res = sig_init();
	EXIT_ON_FAIL(res, "Failed to initialize signal handler.");

	res = arg_proc(argc, argv);	
	EXIT_ON_FAIL(res, "Failed to process arguments.");

	res = sock_create();
	EXIT_ON_FAIL(res, "Failed to create socket.");

	res = addr_create();
	EXIT_ON_FAIL(res, "Failed to create address.");

	res = bind_with();
	EXIT_ON_FAIL(res, "Failed to bind.");

	res = listen_init();
	EXIT_ON_FAIL(res, "Failed to listen.");

	cc_init();

	accept_loop();
}
