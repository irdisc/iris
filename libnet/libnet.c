#define _POSIX_C_SOURCE 200112L
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NI_MAXHOST
#define NI_MAXHOST 1025
#endif

int getsub(const char *domain)
{
	struct addrinfo hints, *res, *p;
	int error;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	error = getaddrinfo(domain, NULL, &hints, &res);
	if (error != 0)
	{
		fprintf(stderr, "error in getaddrinfo: %s\n", gai_strerror(error));
		return EXIT_FAILURE;
	}

	for (p = res; p != NULL; p = p->ai_next)
	{
		char host[NI_MAXHOST] = "";

		error = getnameinfo(p->ai_addr, p->ai_addrlen, host, NI_MAXHOST, NULL, 0, 0);
		if (error != 0)
		{
			fprintf(stderr, "error in getnameinfo: %s\n", gai_strerror(error));
			continue;
		}
		if (*domain != '\0')
			printf("Resolved name: %s\n", host);
	}

	freeaddrinfo(res);
	return EXIT_SUCCESS;
}

int subdomain(const char *domain)
{
	struct addrinfo hints, *res, *p;
	int error;
	const char *sub_list[] = {"www", "dev", "mail", "ftp", "admin", "test", "api", "blog", NULL};

	for (int i = 0; sub_list[i] != NULL; i++)
	{
		char full_domain[256];
		snprintf(full_domain, sizeof(full_domain), "%s.%s", sub_list[i], domain);

		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_DGRAM;

		error = getaddrinfo(full_domain, NULL, &hints, &res);
		if (error != 0)
		{
			fprintf(stderr, "error in getaddrinfo: %s\n", gai_strerror(error));
			return EXIT_FAILURE;
		}

		for (p = res; p != NULL; p = p->ai_next)
		{
			char host[NI_MAXHOST] = "";

			error = getnameinfo(p->ai_addr, p->ai_addrlen, host, sizeof(host), NULL, 0, NI_NUMERICHOST);
			if (error != 0)
			{
				fprintf(stderr, "error in getnameinfo: %s\n", gai_strerror(error));
				continue;
			}
			if (*domain != '\0')
				printf("[+] Found: %s\n", full_domain);
		}

		freeaddrinfo(res);
		return EXIT_SUCCESS;
	}
}
