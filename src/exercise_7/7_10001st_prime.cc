#include <stdio.h>
#include <math.h>
#include <stdlib.h>

short is_prime(long number, long *primes, long i) {
    long square = (long)sqrt(number);

    for (long j = 0; j < i; j++) {
        long prime = *(primes + j);
        if (square < prime) {
            break;
        } else if (number % prime == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char *exercise_name = "10001st prime";
    long answer = 0;
    long current_number = 3;
    long total_primes = 10001;
    long primes[total_primes];
    primes[0] = 2;

    // Your code goes here
    for (long i = 1; i < total_primes; i++) {
        while (is_prime(current_number, &primes[0], i) != 1) {
            current_number += 2;
        }
        primes[i] = current_number;
        current_number += 2;
    }
    answer = primes[total_primes - 1];
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %d\n", answer);
    return 0;
}
