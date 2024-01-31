#include <stdio.h>

int main() {
    char *exercise_name = "Even Fibonacci numbers";
    long answer = 0;

    int fib_prev = 0;
    int fib_current = 1;
    int limit = 4e6;

    // Your code goes here
    while (fib_current < limit) {
        int reg = fib_current + fib_prev;
        fib_prev = fib_current;
        fib_current = reg;

        if (fib_current % 2 == 0) {
            answer += fib_current;
        }
    }
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %d\n", answer);
    return 0;
}
