#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <python3.15/Python.h>

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
            printf("Usage: main.exe [options]\n");
            printf("Options:\n");
            printf("  -h, --help     Show this help message\n");
            printf("  -v, --version  Show version info\n");
            return 0;
        }
        else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0)
        {
            printf("Version 1.0\n");
            return 0;
        }
        else if (strcmp(argv[i], "-hi") == 0 || strcmp(argv[i], "--hello") == 0)
        {
            printf("Hello Word by");
            printf("---------------\n");
        }
        else if (strcmp(argv[i], "-scan") == 0)
        {
            if (i + 2 < argc)
            {
                const char *action = argv[i + 1];
                const char *IP = argv[i + 2];
                int result = -1;
                PyStatus status;
                PyConfig config;
                PyConfig_InitIsolatedConfig(&config);

                wchar_t *wIP = Py_DecodeLocale(IP, NULL);

                wchar_t *args[] = {L"main_app", wIP};
                status = PyConfig_SetArgv(&config, 2, args);

                // Check if the next argument is -mk and if there is a directory name provided
                if (strcmp(action, "-tcp") == 0)
                {
                    status = Py_InitializeFromConfig(&config);
                    FILE *file = fopen("main.py", "r");
                    if (file)
                    {
                        PyRun_SimpleFile(file, "main.py");
                        fclose(file);
                    }
                    Py_Finalize();
                    PyConfig_Clear(&config);
                    PyMem_RawFree(wIP);
                    return 0;
                }
                else if (strcmp(action, "-upd") == 0)
                {
                    printf("tst");
                }
                else
                {
                    printf("Error: -dir requires -mk | -rm <name>\n");
                    return 1;
                }
                // Skip the next two arguments since they have been processed
                i = 2;
                continue;
                // If -dir is provided without enough arguments, print an error message
            }
            else
            {
                printf("Error: -dir requires <action> and <name>\n");
                return 1;
            }
            // If the argument starts with '-' but is not recognized, print an error message
        }
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