#ifndef LIBNET
#define LIBNET

#ifndef NI_MAXHOST
#define NI_MAXHOST 1025
#endif

int getsub(const char *domain);

int subdomain(const char *domain);

#endif
