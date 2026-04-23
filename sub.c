#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

int main()
{
    int found = 0;
    char choce[50];
    char *options[] = {"TEST1", "TEST2"};
    int num_options[2];

#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleOutputCP(65001);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
    printf(GREEN);
    printf("  ▄▄▄▄ ▄▄ ▄▄ ▄▄▄▄  ▄▄▄▄   ▄▄▄  ▄▄   ▄▄  ▄▄▄  ▄▄ ▄▄  ▄▄     ▄▄▄▄▄ ▄▄ ▄▄  ▄▄ ▄▄▄▄  ▄▄▄▄▄ ▄▄▄▄   \n"
           "  ███▄▄ ██ ██ ██▄██ ██▀██ ██▀██ ██▀▄▀██ ██▀██ ██ ███▄██     ██▄▄  ██ ███▄██ ██▀██ ██▄▄  ██▄█▄ \n"
           "  ▄▄██▀ ▀███▀ ██▄█▀ ████▀ ▀███▀ ██   ██ ██▀██ ██ ██ ▀██     ██    ██ ██ ▀██ ████▀ ██▄▄▄ ██ ██ \n");
    printf(RESET "\n");
    printf("------- MENU -------\n");
    for (int i = 0; i < 2; i++)
    {
        printf("Option %d:" BLUE "%s\n" RESET, i + 1, options[i]);
    }

    printf("Please Enter: ");
    scanf("%50s", choce);

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(choce, options[i]) == 0)
        {
            printf("Match found: %s\n", options[i]);
            found = 1;

            // Perform specific action based on match
            if (i == 0)
            {
                printf("Running TEST1 logic...\n");
            }
            break;
        }
    }

    if (!found)
    {
        printf("Error: That option is not in the list!\n");
    }

    return 0;
}