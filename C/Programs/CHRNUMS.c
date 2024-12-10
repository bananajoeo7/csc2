#include <stdio.h>

#define MAXLENGTH 128

void main(argc, argv)
int argc;
char* argv[];
{
    FILE *infp;
    int c, ls;
    ls = 0;
    char line[MAXLENGTH];

    if (argc != 2) {
        printf("Usage: space <filename.txt>\n");
        exit();
    }
    if ((infp = fopen(argv[1], "r")) == NULL) {
        printf("Can’t open %s\n", argv[1]);
        exit();
    }
    while ((c = fgetc(infp)) != EOF) {
        if (c == '\n') {
            line[ls] = '\0';
            printf("%d:  %s\n", ls, line);
            ls = 0;
            continue;
        } 
    }
    fclose(infp);
    return;
}