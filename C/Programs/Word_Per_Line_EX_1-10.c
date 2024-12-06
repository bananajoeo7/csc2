#include <stdio.h>

printf("Print a sentence that you would like printed out line by line:\n");


main (argc, argv)
int argc;
char **argv;
{
        int i;

        for (i = 1; i < argc; i++)
{               printf("%s\n", argv[i]);
        }
}