#include <stdio.h>

#define MAXLENGTH 100

reverseString(length, str) 
char *str; 
int length;
{
    int i, c;
    c = 0;

    for (i = 0; i < length/2; i++) {
        c = str[i];
        str[i] = str[length - (i+1)];
        str[length - (i+1)] = c;
    }

    str[length] = '\0';
    return str;
}

main(argc, argv)
int argc;
char *argv[];
{
    FILE *infp;

    if (argc != 2) {
        printf("Usage: space <filename.txt>\n");
        exit();
    }
    
    if ((infp = fopen(argv[1], "r")) == NULL) {
        printf("Can’t open %s\n", argv[1]);
        exit();
    }

    char line[MAXLENGTH];
    int c, length;

    infp = fopen(argv[1], "r");
    while ((c = fgetc(infp)) != EOF) {
        if (c == '\n') {
            line[length] = '\0';
            printf("%s\n", reverseString(line, length));
            length = 0;
            continue;
        }

        line[length] = c;
        length++;
    }

    if (length != 0) {
        printf("%s\n", reverseString(line, length));
    }

    fclose(infp);
    return 0;
}
