#include <stdio.h>

main (argc, argv)
int argc;
char **argv;
{
        int i;
        
        printf("Here is your sentence with one word on every line: \n");

        for (i = 1; i < argc; i++)
{               printf("%s\n", argv[i]);
        }
}