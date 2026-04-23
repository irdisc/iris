#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXRCVEN 500
#define PORTNUM 2300

int main(int argc, char *argv[])
{
    char buffer[MAXRCVEN + 1];
    int len, subdomain;
    struct sockaddr_in dest;

    subdomain = socket(AF_INET, SOCK_STREAM, 0);
    memset(&dest, 0, sizeof(dest));

    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    dest.sin_port = htons(PORTNUM);

    connect(subdomain, (struct sockaddr *)&dest, sizeof(struct sockaddr_in));

    len = recv(subdomain, buffer, MAXRCVEN, 0);

    buffer[len] = '\0';

    printf("Received %s (%d bytes).\n", buffer, len);

    close(subdomain);
    return EXIT_SUCCESS;
}