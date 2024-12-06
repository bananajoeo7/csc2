#include <stdio.h>

int main(argc, argv) 
    int argc;
    char **argv;
{
    int i; 
    int j;
    int in_blank;
    in_blank = 0;
    printf("Enter Test Case for Additional Blank Remover:\n");

    for (i = 1; i < argc; i++) {
        for (j = 0; argv[i][j] != '\0'; j++) {
            if (argv[i][j] == ' ') {
                if (!in_blank) {
                    putchar(' ');
                    in_blank = 1;
                }
            } else {
                putchar(argv[i][j]); 
                in_blank = 0;       
            }
        }

        
        if (i < argc - 1) {
            putchar(' '); 
        }
    }

    putchar('\n');
    return 0;
}
