/*
 * Copyright (c) 2026 Nora Rose. All rights reserved.
 *
 * DUAL-LICENSING NOTICE:
 * This software is licensed under two separate license agreements:
 *
 * 1. PROPRIETARY LICENSE: For commercial use, income generation, or
 *    distribution for profit. This use is strictly prohibited without
 *    prior written consent from Nora Rose.
 *
 * 2. MIT LICENSE: For personal, educational, or non-commercial use.
 *    See LICENSE-MIT for the full license text.
 *
 * SPDX-License-Identifier: MIT OR LicenseRef-Proprietary-Nora-Rose
 *
 * DISCLAIMER:
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 */

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
