#include <stdio.h>

long squeare_of_the_sum(long n) {
    long sum = (n * (n + 1)) / 2;
    return sum * sum;
}

long sum_of_the_square(long n) {
    return (n * (n + 1) * ( 2 * n  + 1)) / 6;
}

int main() {
    char *exercise_name = "Sum square difference";
    long answer = 0;
    long limit = 100;

    // Your code goes here
    answer = squeare_of_the_sum(limit) - sum_of_the_square(limit);
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %d\n", answer);
    return 0;
}
