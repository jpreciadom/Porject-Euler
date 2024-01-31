#include <stdio.h>

int main() {
    char *exercise_name = "Largest prime factor";
    long answer = 0;
    long number = 600851475143;
    long factor = 3;

    // Your code goes here
    while (factor <= number) {
        if (number % factor == 0) {
            number /= factor;
            answer = factor;
        } else {
            factor += 2;
        }
    }
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %d\n", answer);
    return 0;
}
