#include "sender.h"

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
	
	res = connect_to();
	EXIT_ON_FAIL(res, "Failed to connect.");

	ml_start();
}
