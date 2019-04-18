#undef NDEBUG
#include <stdlib.h>
#include <sys/select.h>
#include <stdio.h>
#include <ringbuffer.h>
#include <dbg.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

struct tagbstring NL = bsStatic("\n");
struct tagbstring CRLF = bsStatic("\r\n");

int nonblock(int fd)
{
	int flags = fcntl(fd, F_GETFL, 0);
	check(flags >= 0, "Invalid flags on nonblock.");

	int rc = fcntl(fd, F_SETFL, flags | O_NONBLOCK);
	check(rc == 0, "Can't set nonbloking");

	return 0;
error:
	return -1;
}

int client_connect(char *host, char *port)
{
	int rc = 0;
	struct addrinfo *addr = NULL;

	rc = getaddrinfo(host, port, NULL, &addr);
	check(rc == 0, "Failed to lookup %s:%s", host, port);

	int sock = socket(AF_INET, SOCK_STREAM, 0);
	check(sock >= 0, "Can not create socket.");

	rc = connect(sock, addr->ai_addr, addr->ai_addrlen);
	check(rc == 0, "Connect failed.");

	rc = nonblock(sock);
	check(rc == 0, "Can't set nonblocking.");

	freeaddrinfo(addr);
	return sock;

error:
	freeaddrinfo(addr);
	return -1;
}


