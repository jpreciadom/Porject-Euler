#include <stdio.h>
#include <math.h>

int main() {
    char *exercise_name = "Special Pythagorean triplet";
    long answer = 0;

    // Your code goes here
    int a = 1, b = 2, c = 997;
    for (a = 1; a < b; a++) {
        for (b = a + 1; b < c; b++) {
            c = 1000 - a - b;
            double result = pow(a, 2) + pow(b, 2) - pow(c, 2);
            if (result == 0.0) {
                answer = a*b*c;
            }
        }
    }
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %ld\n", answer);
    return 0;
}
