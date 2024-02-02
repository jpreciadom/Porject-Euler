#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct linked_node {
    int number;
    struct linked_node *next_node;
};

struct linked_list {
    struct linked_node *first_node;
    struct linked_node *last_node;
    long size;  
};

short is_prime(long number, struct linked_list *primes) {
    long square = (long)sqrt(number);
    struct linked_node *current = primes->first_node;

    while(current != NULL) {
        long prime = current->number;
        if (square < prime) {
            break;
        } else if (number % prime == 0) {
            return 0;
        }
        current = current->next_node;
    }
    return 1;
}

int main() {
    char *exercise_name = "Summation of primes";
    long answer = 0;
    long limit = 2e6;

    // Your code goes here
    struct linked_node *node = (struct linked_node *) malloc(sizeof(struct linked_node));
    node->number = 2;
    node->next_node = NULL;

    struct linked_list primes = { node, node, 1 };
    answer += 2;

    for (long i = 3; i < limit; i+=2) {
        if (is_prime(i, &primes) == 1) {
            node = (struct linked_node *) malloc(sizeof(struct linked_node));
            primes.last_node->next_node = node;
            primes.last_node = node;
            primes.size++;
            node->number = i;
            node->next_node = NULL;
            answer += i;
        }
    }
    // Your code ends here

    printf("%s\n", exercise_name);
    printf("Answer: %ld\n", answer);
    return 0;
}
