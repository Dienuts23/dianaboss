#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main ()

{	
	int sock_fd, err, client_fd;
	unsigned int addrlen;
	struct sockaddr_in local_addr, client_addr;
	
	sock_fd = socket (AF_INET, SOCK_STREAM, 0);
	if (sock_fd < 0) {
		fprintf (stderr, "Eroare! Nu am putut deschide socket!\n");
		exit (-1);
	}

	memset (&local_addr, 0, sizeof(local_addr));
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons (5005);
	local_addr.sin_addr.s_addr = INADDR_ANY;

	err = bind (sock_fd, (struct sockaddr *) &local_addr, sizeof(local_addr));

	if (err < 0)
	{
		fprintf (stderr, "Eroare la bind!\n");
		exit (-1);
	}

	err = listen (sock_fd, 10);	


	if (err < 0)
	{
		fprintf (stderr, "Eroare la listen\n");
		exit (-1);
	}

	memset (&client_addr, 0, sizeof(client_addr));
	addrlen = sizeof(client_addr);
	client_fd = accept (sock_fd, (struct sockaddr *) &client_addr, &addrlen);

	if (client_fd < 0)
	{
		fprintf (stderr, "Eroare la accept\n");
		exit (-1);
	}

	char buffer[32];
	read (client_fd, buffer, sizeof(buffer));

	printf ("%s\n", buffer);

	close (client_fd);
	close (sock_fd);

	return 0;
}