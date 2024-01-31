#include <stdio.h>

long gcd(long a, long b) {
    long reg_a = a;
    long reg_b = b;

    while (reg_a != reg_b) {
        if (reg_a > reg_b) {
            reg_a -= reg_b;
        } else {
            reg_b -= reg_a;
        }
    }

    return reg_a;
}

long lcm(long a, long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    char *exercise_name = "Smallest multiple";
    long answer = 2;
    int limit = 20;

    // Your code goes here
    for (int i = 3; i < limit; i++) {
        answer = lcm(answer, i);
    }
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %d\n", answer);
    return 0;
}
