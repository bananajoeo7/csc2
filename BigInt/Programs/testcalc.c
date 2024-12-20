#include <stdio.h>

struct bigint {
    char negative;
    char numdigits;
    char digits[10];
};

int main() {
    char input[100];
    printf("Enter a string of digits: ");
    scanf("%99s", input);

    int input_len;
    input_len = 0;
    while (input[input_len] != '\0') {
        input_len++;
    }

    printf("Chunks of 9 digits:\n");

    for (int i = 0; i < input_len;) {
        i += 9;

        struct bigint chunk;
        chunk.negative = 0;
        chunk.numdigits = 0;

        int j;
        for (j = 0; j < 9 && (i + j) < input_len; j++) {
            chunk.digits[j] = input[i + j];
        }
        chunk.digits[j] = '\0';
        chunk.numdigits = j;

        printf("Chunk %d: %s\n", (i/9) + 1, chunk.digits);
    }

    return 0;
}
