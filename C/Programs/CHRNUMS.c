#include <stdio.h>

void main(argc, argv)
int argc;
char* argv[];
{
    FILE *infp;
    int c, nc, ls;
    int nc = 0;
    int ls = 0;

    if (argc != 2) {
        printf("Usage: wc <infile>\n");
        exit();
    }
    if ((infp = fopen(argv[1], "r")) == NULL) {
        printf("Can’t open %s\n", argv[1]);
        exit();
    }
    while ((c = fgetc(infp)) != EOF) {
        ++nc;
        if (c == '\n') {
            printf("%d:")
        } 
    }
    fclose(infp);
    printf("  %d %d %d %s\n", nl, nw, nc, argv[1]);
}