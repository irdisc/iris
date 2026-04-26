#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        char *DOMAIN = strdup(argv[1]);
        if (DOMAIN == NULL)
            return 1;
        printf("%s", DOMAIN);
        free(DOMAIN);
    }
    else
    {
        printf("No argument was transferred.\n");
    }
    return 0;
}