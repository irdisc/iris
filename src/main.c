#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <python3.15/Python.h>

/*
 * Copyright (c) 2026 Nora Rose
 * All rights reserved.
 * This code is proprietary of Nora Rose.
 */

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("No arguments provided. Use -h for help.\n"); // Added semicolon here
        return 0;
    }
    // Process command-line arguments
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            printf("Usage: iris+ [options]\n");
            printf("Options:\n");
            printf("  -h, --help     Show this help message\n");
            printf("  -v, --version  Show version info\n");
            printf("--------------- SCAN PORT ---------------\n");
            printf("  -scan, requires -tcp or -udp and <IP> Optional: > -ipv6\n");
            return 0;
        }
        else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0)
        {
            printf("Iris+ | Version 1.0\n");
            return 0;
        }
        else if (strcmp(argv[i], "-hi") == 0 || strcmp(argv[i], "--hello") == 0)
        {
            printf("Hello Word by");
            printf("---------------\n");
        }
        else if (strcmp(argv[i], "-scan") == 0) // Added check for -scan action
        {
            if (i + 2 < argc)
            {
                const char *action = argv[i + 1];                         // Required argument for action (-tcp or -udp)
                const char *IP = argv[i + 2];                             // Required argument for IP address
                const char *IPv6 = (i + 3 < argc) ? argv[i + 3] : "IPv4"; // Optional argument for IPv6, default to "IPv4" if not provided
                int result = -1;
                PyStatus status;
                PyConfig config;
                PyConfig_InitIsolatedConfig(&config);

                wchar_t *wIP = Py_DecodeLocale(IP, NULL);
                wchar_t *waction = Py_DecodeLocale(action, NULL);
                wchar_t *wIPv6 = Py_DecodeLocale(IPv6, NULL);

                wchar_t *args[] = {waction, wIP, wIPv6};
                status = PyConfig_SetArgv(&config, 3, args); // Set the command-line arguments for the Python interpreter

                // Check if the action is -tcp or -udp and run the corresponding Python code
                if (strcmp(action, "-tcp") == 0)
                {
                    status = Py_InitializeFromConfig(&config);
                    FILE *file = fopen("/scripts/main.py", "r");
                    if (file)
                    {
                        PyRun_SimpleFile(file, "/scripts/main.py");
                        fclose(file);
                    }
                    Py_Finalize();
                    PyConfig_Clear(&config);
                    PyMem_RawFree(wIP);
                    return 0;
                }
                else if (strcmp(action, "-udp") == 0) // Added check for -udp action
                {
                    status = Py_InitializeFromConfig(&config);
                    FILE *file = fopen("/scripts/main.py", "r");
                    if (file)
                    {
                        PyRun_SimpleFile(file, "/scripts/main.py");
                        fclose(file);
                    }
                    Py_Finalize();
                    PyConfig_Clear(&config);
                    PyMem_RawFree(wIP);
                    return 0;
                }
            }
            else
            {
                printf("Er111ror: -scan requires -tcp | -udp <192.0.2.1>\n");
                return 1;
            }
            // Move the index past the arguments for -scan
            i = 2;
            continue;
            // If -scan is provided without enough arguments, print an error message
        }
        else if (strcmp(argv[i], "-resfinder") == 0)
        {
            if (i + 2 < argc)

            {
                const char *action = argv[i + 1]; // Required argument for action (-tcp or -udp)
                const char *DOMAIN = argv[i + 2]; // Required argument for IP address
                // const char *IPv6 = (i + 3 < argc) ? argv[i + 3] : "IPv4"; // Optional argument for IPv6, default to "IPv4" if not provided
                int result = -1;
                PyStatus status;
                PyConfig config;
                PyConfig_InitIsolatedConfig(&config);

                wchar_t *wIP = Py_DecodeLocale(DOMAIN, NULL);
                wchar_t *waction = Py_DecodeLocale(action, NULL);
                // wchar_t *wIPv6 = Py_DecodeLocale(IPv6, NULL);

                wchar_t *args[] = {waction, wIP};
                status = PyConfig_SetArgv(&config, 2, args);
                if (strcmp(action, "-find") == 0)
                {
                    execlp("./resfinder", "./iris+", argv[3], NULL);
                    return 1;
                }
            }
            else
            {
                printf("Error: -resfinder requires -find <google.com>\n");
                return 1;
            }
        }

        // If the argument starts with '-' but is not recognized, print an error message

        else if (argv[i][0] == '-')
        { // Removed the extra ']' here
            printf("Unknown option: %s\n", argv[i]);
            return 1;
        }
        else
        {
            printf("Processing file: %s\n", argv[i]);
        }
    }
    return 0;
}