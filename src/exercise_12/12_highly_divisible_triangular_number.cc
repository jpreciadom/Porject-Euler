#include <stdio.h>

int main() {
    char *exercise_name = "Highly divisible triangular number";
    long answer = 0;

    // Your code goes here
    long num_of_factors = 1;
    long n = 1;
    while(num_of_factors < 500) {
        long current_triangular_number = (n * (n + 1)) / 2;

        num_of_factors = 1;
        for (int i = current_triangular_number / 2; i > 0; i--) {
            if (current_triangular_number % i == 0) {
                num_of_factors++;
            }
        }
        answer = current_triangular_number;
        n++;
    }
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %ld\n", answer);
    return 0;
}
