#include <stdio.h>

main (argc, argv)
int argc;
char **argv;
{
        int i;

        for (i = 1; i < argc; i++)
{               printf("%s\n", argv[i]);
        }
}