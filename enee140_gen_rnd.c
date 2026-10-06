#include <limits.h>
#include <stdio.h>
#include <math.h>

unsigned X;
unsigned m;
unsigned A;
unsigned B;

void seed_rnd (unsigned seed, int algorithm) {
    if (algorithm == 1) {
        m = 32;
        A = 214013;
        B = 2531011;
    }
    else if (algorithm == 2) {
        m = 32;
        A = 1103515245;
        B = 12345;
    }
    else if (algorithm == 3) {
        m = 31;
        A = 1103515245;
        B = 12345;
    }

    X = seed;
}

void get_rnd_max() {
    unsigned RND_MAX;
    if (m == 32) {
        RND_MAX = UINT_MAX;
    }
    else if (m == 31) {
        RND_MAX = (1U << 31) - 1;
    }
    printf("%u\n", RND_MAX);
}

unsigned gen_rnd() {
    unsigned number1;
    if (m == 32) {
        
    }
}

unsigned gen_rnd_limit(unsigned limit) {

}

int gen_rnd_range(int min_gen, int max_gen) {

}

float gen_rnd_float(float min_gen, float max_gen) {

}

float gen_rnd_exp(float mean) {

}

int main() {
    int input = 0;
    int count = 0;
    int input2 = 0;
    int count2 = 0;
    unsigned seed = 0;

    printf("Welcome to the ENEE140 pseudo-random number generator!\n");
    printf("1: Print RND_MAX\n");
    printf("2: Generate uniformly-distributed positive integers\n");
    printf("3: Generate uniformly-distributed positive integers, up to a given limit\n");
    printf("4: Generate uniformly-distributed integers, from a given range\n");
    printf("5: Generate uniformly-distributed floats, from a given range\n");
    printf("6: Generate exponentially-distributed floats\n");

    printf("\nEnter your choice (1-6):\n");
    scanf("%d", &input);

    while (count < 3) {
        if (input >= 1 && input <= 6) {
            break;
        }
        else {
            count++;
            if (count == 3) {
            printf("You have entered 3 invalid options. Goodbye!");
                return 0;
            }
            printf("Sorry, that is not a valid option\nEnter your choice (1-6):\n");
            scanf("%d", &input);
        }
    }

    printf("Select the algorithm to use.\nEnter your choice (1-3):\n");
    scanf("%d", &input2);

    while (count2 < 3) {
        if (input2 >= 1 && input2 <= 3) {
            break;
        }
        else {
            count2++;
            if (count2 == 3) {
                printf("You have entered 3 invalid options. Goodbye!");
                return 0;
            }
            printf("Sorry, that is not a valid option\nEnter your choice (1-3):\n");
            scanf("%d", &input2);
        }
    }

    printf("Select the seed for the random number generator:\n");
    scanf("%u", &seed);
    seed_rnd(seed, input2);

    if (input == 1) {
        get_rnd_max();
    }
    else if (input == 2) {
        int input3;
        printf("How many numbers should I generate:");
        scanf("%d", &input3);
    }
    else if (input == 3) {

    }
    else if (input == 4) {

    }
    else if (input == 5) {

    }
    else if (input == 6) {

    }
}
