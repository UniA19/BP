#include <stdio.h>

int calc_bisect(int x);
void cut_in_half(int * x);

int main(void)
{
        int n1 = 5;
        int n2 = 5;
        printf("n1 = %i n2 = %i\n", n1, n2);
        printf("calc_bisect(n1) = calc_bisect(%i) = %i\n", n1, calc_bisect(n1));
        printf("cut_in_half(&n2) = calc_bisect(%p)\n", (void *)&n2);
        cut_in_half(&n2);
        printf("(value) n1 = %i (value) n2 = %i\n", n1, n2);
        return 0;
}

int calc_bisect(int x)
{
        return x / 2;
}

void cut_in_half(int * x)
{
        *x /= 2;
}
