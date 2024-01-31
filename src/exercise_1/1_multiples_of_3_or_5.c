#include <stdio.h>

int main() {
    char *exercise_name = "Multiples of 3 or 5";
    long answer = 0;
    int limit = 1000;

    // Your code goes here
    for (int i = 3; i < limit; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            answer+=i;
        }
    }
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %d\n", answer);
    return 0;
}
