#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define N 10

unsigned int my_interval_rand(unsigned int u, unsigned int o);
void array_init(unsigned int w[], unsigned int n, unsigned int u, unsigned int o);
unsigned int array_second_min(unsigned int w[], unsigned int n);


int main()
{
    unsigned int array[N];
    unsigned int i;

    srand(time(NULL));

    array_init(array, N, 100000, 999999);

    for (i = 0; i < N; ++i) {
        printf("%i\n", array[i]);
    }

    printf("second min: %i\n", array_second_min(array, N));

    return 0;
}


unsigned int my_interval_rand(unsigned int u, unsigned int o)
{
    unsigned int random_nr;

    if (u > o) {
        unsigned int holder = o;
        o = u;
        u = holder;
    }

    random_nr = (rand() % (o - u + 1)) + u;
    return random_nr;
}

void array_init(unsigned int w[], unsigned int n, unsigned int u, unsigned int o)
{
    unsigned int i;
    for (i = 0; i < n; ++i) {
        w[i] = my_interval_rand(u, o);
    }
}

unsigned int array_second_min(unsigned int w[], unsigned int n)
{
    unsigned int min = UINT_MAX;
    unsigned int second_min = UINT_MAX;

    unsigned int i;

    if (n <= 1) {
        return UINT_MAX;
    }

    for (i = 0; i < n; ++i) {
        if (w[i] < min) {
            min = w[i];
        }
    }

    for (i = 0; i < n; ++i) {
        if (w[i] < second_min && w[i] != min) {
            second_min = w[i];
        }
    }

    return second_min;
}
