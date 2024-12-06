#include <stdio.h>

main (argc, argv)
int argc;
char **argv;
{
        int i;

        printf("Print a sentence that you would like printed out line by line:\n");

        for (i = 1; i < argc; i++)
{               printf("%s\n", argv[i]);
        }
}