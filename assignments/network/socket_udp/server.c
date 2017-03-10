#include "header.h"

#define SER_PORTNO 5720
#define SER_IPADDR 0xac1005da

int main (int argc, char *argv[]) {
	int sockfd;
	struct sockaddr_in s_addr;	// Server
	struct sockaddr_in c_addr;	// Client
	char *buf = NULL;	// Buffer to store received data
	socklen_t size = sizeof(struct sockaddr_in);

	if ((buf = (char *) malloc (sizeof (char) * MAX_BUF)) == NULL)
		error_handler("malloc(buf) failed\n");

	sockfd = socket (PF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1) error_handler("socket() failed\n");

	memset (&s_addr, '\0', sizeof (s_addr));	// Clear structure	

	s_addr.sin_family = PF_INET;
	s_addr.sin_port = htons (SER_PORTNO);
	s_addr.sin_addr.s_addr = htonl (SER_IPADDR);

	if (bind (sockfd, (struct sockaddr *)&s_addr, sizeof (struct sockaddr_in)) == -1)
		error_handler("bind() failed\n");

	do {
			memset (buf, '\0', MAX_BUF);	// Clear buffer	
			if (recvfrom (sockfd, buf, MAX_BUF, 0, (struct sockaddr *)&c_addr,
									&size) == -1)
					error_handler("recvfrom() failed\n");

			printf ("Request received\n");
			fwrite (buf, MAX_BUF, 1, stdout);

			memset (buf, '\0', MAX_BUF);	// Clear buffer	
			strcpy (buf, "I am server");

			if (sendto (sockfd, buf, MAX_BUF, 0, (struct sockaddr *)&c_addr,
									size) == -1)
					error_handler("sendto() failed\n");
	} while (1);

	close(sockfd);

	return 0;
}
