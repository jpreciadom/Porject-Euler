#include <stdio.h>
#include <stdlib.h>

short **get_numbers() {
    int amount_of_numbers = 20 * 20;
    char *c_numbers = (char *) malloc(sizeof(char) * amount_of_numbers * 3);

    FILE *numbers_file = fopen("src/exercise_11/numbers.txt", "r");
    if (numbers_file == NULL) {
        perror("Error opening the numbers file");
        return NULL;
    }

    short **numbers = (short **) malloc(sizeof(short *) * 20);
    for (int i = 0; i < 20; i++) {
        *(numbers + i) = (short *) malloc(sizeof(short) * 20);

        size_t ret = fread(c_numbers, 3, 20, numbers_file);
        if (ret != 20) {
            perror("Error reading the numbers");
            return NULL;
        }

        for (int j = 0; j < 20; j++) {
            *(*(numbers + i) + j) = atoi(c_numbers + (j * 3));
        }
    }
    fclose(numbers_file);
    free(c_numbers);

    return numbers;
}

int main() {
    char *exercise_name = "Largest product in a grid";
    long answer = 0;
    short adjacent_numbers = 4;

    // Your code goes here
    short **numbers = get_numbers();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            long products[8] = {1, 1, 1, 1, 1, 1, 1, 1};
            for (int k = 0; k < adjacent_numbers; k++) {
                long number, x, y, *product;
                // Diagonal Up-left
                y = (i - k + 20) % 20; x = (j - k + 20) % 20;
                product = &products[0];
                number = *(*(numbers + y) + x);
                *product *= number;
                // Vertical Up
                y = (i - k + 20) % 20; x = j;
                product = &products[1];
                number = *(*(numbers + y) + x);
                *product *= number;
                // Diagonal Up-right
                y = (i - k + 20) % 20; x = (j + k) % 20;
                product = &products[2];
                number = *(*(numbers + y) + x);
                *product *= number;
                // Horizontal left
                y = i; x = (j - k + 20) % 20;
                product = &products[3];
                number = *(*(numbers + y) + x);
                *product *= number;
                // Horizontal right
                y = i; x = (j + k) % 20;
                product = &products[4];
                number = *(*(numbers + y) + x);
                *product *= number;
                // Diagonal Down-left
                y = (i + k) % 20; x = (j - k + 20) % 20;
                product = &products[5];
                number = *(*(numbers + y) + x);
                *product *= number;
                // Vertical down
                y = (i + k) % 20; x = j;
                product = &products[6];
                number = *(*(numbers + y) + x);
                *product *= number;
                // Diagonal Down right
                y = (i + k) % 20; x = (j + k) % 20;
                product = &products[7];
                number = *(*(numbers + y) + x);
                *product *= number;
            }

            for (int k = 0; k < 8; k++) {
                if (answer < products[k]) {
                    answer = products[k];
                }
            }
        }
    }
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %ld\n", answer);
    return 0;
}
