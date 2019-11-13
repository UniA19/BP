#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define array_size 10
#define my_rand_min 10
#define my_rand_max 99

unsigned int my_interval_rand(unsigned int u, unsigned int o);

void array_init(unsigned int w[], unsigned int n, unsigned int u, unsigned int o);

unsigned int array_second(unsigned int w[], unsigned int n);

int main(void)
{
        int i;
        unsigned int array[array_size];
        srand(time(NULL));
        array_init(array, array_size, my_rand_min, my_rand_max);
        for (i = 0; i < array_size; ++i){
                printf("%u\n", array[i]);
        }
        printf("%u", array_second(array, array_size));
        return 0;
}

unsigned int my_interval_rand(unsigned int u, unsigned int o)
{
        int temp, zufall;
        if ( u > o){
                temp = u;
                u = o;
                o = temp;
        }
        if (o > RAND_MAX -1 - u){
                o = RAND_MAX - u -1;
        }
        zufall = (rand() % (o + 1)) + u;
        return zufall;
}

void array_init(unsigned int w[], unsigned int n, unsigned int u, unsigned int o)
{
        unsigned int i;
        for (i = 0; i < n; ++i){
                w[i] = my_interval_rand(u, o);
        }
        return;
}

unsigned int array_second(unsigned int w[], unsigned int n)
{
        unsigned int i, array_second, array_min;
        array_min = UINT_MAX;
        array_second = UINT_MAX;
        for (i = 0; i < n; ++i){
                if(w[i] < array_min){
                        array_second = array_min;
                        array_min = w[i];
                }
        }
        return array_second;
}
