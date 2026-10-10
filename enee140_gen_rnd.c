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
    unsigned rnd_max;
    if (m == 32) {
        rnd_max = UINT_MAX;
    }
    else if (m == 31) {
        rnd_max = (1U << 31) - 1;
    }
    printf("%u\n", rnd_max);
}

unsigned gen_rnd() {
    if (m == 32) {
        X = A * X + B;
    }
    else {
        unsigned M = 1U << 31;
        X = (A * X + B) % M;
    }
    return X;
}

unsigned gen_rnd_limit(unsigned limit) {
    unsigned genrnd = gen_rnd();
    return genrnd % (limit + 1);
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

    while (1) {
        printf("Welcome to the ENEE140 pseudo-random number generator!\n");
        printf("1: Print RND_MAX\n");
        printf("2: Generate uniformly-distributed positive integers\n");
        printf("3: Generate uniformly-distributed positive integers, up to a given limit\n");
        printf("4: Generate uniformly-distributed integers, from a given range\n");
        printf("5: Generate uniformly-distributed floats, from a given range\n");
        printf("6: Generate exponentially-distributed floats\n");

        printf("\nEnter your choice (1-6): ");
        scanf("%d", &input);

        while (count < 3) {
            if (input >= 1 && input <= 6) {
                break;
            }
            else {
                count++;
                if (count == 3) {
                    printf("You have entered 3 invalid options. Goodbye!\n");
                    return 0;
                }
                printf("Sorry, that is not a valid option\nEnter your choice (1-6): ");
                scanf("%d", &input);
            }
        }

        printf("Select the algorithm to use.\nEnter your choice (1-3): ");
        scanf("%d", &input2);

        while (count2 < 3) {
            if (input2 >= 1 && input2 <= 3) {
                break;
            }
            else {
                count2++;
                if (count2 == 3) {
                    printf("You have entered 3 invalid options. Goodbye!\n");
                    return 0;
                }
                printf("Sorry, that is not a valid option\nEnter your choice (1-3): ");
                scanf("%d", &input2);
            }
        }

        printf("Select the seed for the random number generator: ");
        scanf("%u", &seed);
        seed_rnd(seed, input2);

        if (input == 1) {
            get_rnd_max();
            printf("\n");
            continue;
        }
        else {
            break;
        }
    }

    if (input == 2) {
        int input3;
        int count3;
        printf("How many numbers should I generate: ");
        scanf("%d", &input3);
        for (count3 = 0; count3 < input3; ++count3) {
            unsigned output1 = gen_rnd();
            printf("%u ", output1);
        }
        printf("\n");
    }
    else if (input == 3) {
        int input4;
        int input5;
        int count4;
        printf("How many numbers should I generate: ");
        scanf("%d", &input4);
        printf("Enter the maximum number to generate: ");
        scanf("%d", &input5);
        for (count4 = 0; count4 < input4; ++count4) {
            unsigned output2 = gen_rnd_limit(input5);
            printf("%u ", output2);
        }
    }
    else if (input == 4) {
        int input6;
        int input7;
        int input8;
        int count6;
        printf("How many numbers should I generate: ");
        scanf("%d", &input6);
        printf("Enter the minimum number to generate: ");
        scanf("%d", &input7);
        printf("Enter the maximum number to generate: ");
        scanf("%d", &input8);
        for (count6 = 0; count6 < input6; ++count6) {
            int output6 = gen_rnd_range(input7, input8);
            printf("%d ", output6);
        }
        printf("\n");

    }
    else if (input == 5) {
        int input9;
        float input10;
        float input11;
        float count6;
        printf("How many numbers should I generate: ");
        scanf("%d", &input9);
        printf("Enter the minimum number to generate: ");
        scanf("%f", &input10);
        printf("Enter the maximum number to generate: ");
        scanf("%f", &input11);
        for (count6 = 0; count6 < input9; ++count6) {
            float output7 = gen_rnd_float(input10, input11);
            printf("%.2f ", output7);
        }
        printf("\n");

    }
    else if (input == 6) {
        int input12;
        float input13;
        int count4 = 1;
        int count5;
        printf("How many numbers should I generate: ");
        scanf("%d", &input12);
        while (count4 == 1) {
            printf("Enter the mean of the distribution: ");
            scanf("%f", &input13);
            if (input13 >= 0) {
                for (count5 = 0; count5 < input12; ++count5) {
                    float output6 = gen_rnd_exp(input13);
                    printf("%.2f ", output6);
                }
                printf("\n");
            }
            else {
                printf("Error: the mean must be a positive number.\n");
            }
        }
    }
}
