#include <stdio.h>
#include <stdlib.h>

short *get_numbers() {
    char *digits = (char *)malloc(sizeof(char) * 51 * 20);

    FILE *numbers = fopen("src/exercise_8/number.txt", "r");
    if (numbers == NULL) {
        perror("Error opening the number file");
        return NULL;
    }

    size_t ret = fread(digits, 51, 20, numbers);
    if (ret != 20) {
        perror("Error while reading the digits\n");
        return NULL;
    }

    short *digits_s = (short *) malloc(sizeof(short) * 1000);
    for (int i = 0; i < 20; i++) {
        short *raw = digits_s + (i * 50);
        for (int j = 0; j < 50; j++) {
            short pos = (i * 51) + j;
            char digit[] = {*(digits + pos), '\0'};
            *(raw + j) = atoi(&digit[0]);
        }
    }

    free(digits);
    fclose(numbers);
    return digits_s;
}

int main() {
    char *exercise_name = "Largest product in a series";
    long answer = 0;
    short digits = 13;

    // Your code goes here
    short *numbers = get_numbers();
    if (numbers == NULL) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 50; j++) {
            long product = 1;
            for (int k = 0; k < digits; k++) {
                int pos = ((i * 50) + (j + k)) % 1000;
                short term = (short)*(numbers + pos);
                product *= term;
            }

            if (product > answer) {
                answer = product;
            }
        }
    }
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %ld\n", answer);
    return 0;
}
