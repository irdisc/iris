#ifndef LIBNET
#define LIBNET

void getaddrinfo(const char *node,
                 const char *service,
                 const struct addrinfo *hints,
                 struct addrinfo **res);

void freeaddrinfo(struct addrinfo *res);

#endif
