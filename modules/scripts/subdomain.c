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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libnet.h>
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		char *DOMAIN = strdup(argv[1]);
		if (DOMAIN == NULL)
			return 1;
		subdomain(DOMAIN);
		free(DOMAIN);
	}
	else
	{
		printf("No argument was transferred.\n");
	}
	return 0;
}