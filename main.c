#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main ()

{	
	int sock_fd, err;
	struct sockaddr_in local_addr, server_addr;
	
	err = socket (AF_INET, SOCK_STREAM, 0);
	if (err < 0) {
		fprintf (stderr, "Eroare! Nu am putut deschide socket!\n");
		exit (-1);
	}

	memset (&local_addr, 0, sizeof(local_addr));
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons (5005);

	err = inet_pton (AF_INET, "127.0.0.1", &local_addr.sin_addr.s_addr);

	if (err < 0)
	{
		fprintf (stderr, "Eroare! Nu am putut converti adresa!\n");
		exit (-1);
	}

	err = bind (sock_fd, (struct sockaddr *) &local_addr, sizeof(local_addr));

	if (err < 0)
	{
		fprintf (stderr, "Eroare la bind!\n");
		exit (-1);
	}

	memset (&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons (5005);

	



	return 0;
}