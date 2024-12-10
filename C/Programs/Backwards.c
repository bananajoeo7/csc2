#include <stdio.h>

#define MAXLENGTH 128

reverseString(length, str) 
char *str; 
int length;
{
    int c;
    char *temp;

    for (i = 0; i < length/2; i++) {
        temp = str[i];
        str[i] = str[length - (i + 1)];
        str[length - (i + 1)] = temp;
    }
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
    int length;

    while (fgets(line, sizeof(line), infp)) {
        
    }

    fclose(infp);
    return 0;
}
