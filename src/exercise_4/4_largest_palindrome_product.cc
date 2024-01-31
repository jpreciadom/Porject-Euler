#include <stdio.h>

long reverse(long number) {
    long reverse_number = 0;
    while (number > 0) {
        reverse_number = (reverse_number * 10) + (number % 10);
        number/=10;
    }
    return reverse_number;
}

long my_pow(long a, long b) {
    long result = 1;
    for (int i = 0; i < b; i++) {
        result*=a;
    }
    return result;
}

int main() {
    char *exercise_name = "Largest palindrome product";
    long answer = 0;

    int found = 0;
    int num_of_digits = 3;
    long max_number = my_pow(10, num_of_digits);
    long current_number = max_number * max_number;

    // Your code goes here
    while (found == 0) {
        long reverse_number = reverse(current_number);
        if (current_number == reverse_number) {
            long factor = max_number;
            while (current_number % factor != 0) {
                factor--;
            }

            if (current_number / factor > max_number) {
                current_number--;
            } else {
                answer = current_number;
                found = 1;
            }
        } else {
            current_number--;
        }
    }
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %d\n", answer);
    return 0;
}
