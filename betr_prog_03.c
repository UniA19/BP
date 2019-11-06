#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


void aufg_31a()
{
    int i;
    for (i = 0; i < 7; ++i) {
        int j;
        for (j = 1; j <= 7; ++j) {
            printf("%-4i", 7 * i + j);
        }
        putchar('\n');
    }
}

void aufg_31b()
{
    int i;
    for (i = 1; i <= 10; ++i) {
        int j;
        for (j = 1; j <= 10 - i; ++j) {
            putchar(' ');
        }
        for (j = 1; j <= i; ++j) {
            putchar('*');
        }
        putchar('\n');
    }
}

double decrement(double x)
{
    return --x;
}

void aufg_32a()
{
    double d;
    d = (double)rand() / RAND_MAX * 9 + 0.5;
    printf("%f\n", d);
    printf("%f\n", decrement(d));
}

int my_toupper(int c)
{
    return (('a' <= c && c <= 'z') ? c - 'a' + 'A' : c);
}

void aufg_32b()
{
    char c = rand() % 128;
    printf("%c\n", c);
    printf("%c\n", my_toupper(c));
}

void print_alarm(int size)
{
    int i;
    if (size < 0) {
        printf("Illeagal argument exception in function print_alarm(int size)\n");
        printf("The function parameter size = %i, which is < 0\n", size);
        return;
    }
    for (i = 0; i < size; ++i) {
        putchar('\a');
    }
}

void aufg_33a()
{
    print_alarm(3);
    print_alarm(0);
    print_alarm(-5);
}

double power3(int n)
{
    int ret = 1.0;
    if (n >= 0) {
        int i;
        for (i = 0; i < n; ++i) {
            ret *= 3;
        }
    } else {
        int i;
        for (i = 0; i > n; --i) {
            ret /= 3;
        }
    }
    return ret;
}

void aufg_33b()
{
    int i;
    for (i = 1; i <= 13; ++i) {
        printf("%f\n", power3(i));
    }
}

void aufg_34a()
{
    int i;
    int a[4];
    a[0] = 144;
    a[1] = sqrt(a[0]);
    a[2] = a[0] - a[1];
    a[3] = a[2] / 6;
    for (i = 0; i < 4; ++i) {
        printf("%i\n", a[i]);
    }
}

void aufg_34b()
{
    char b[16];
    int i;
    for (i = 0; i < 16; ++i) {
        if (i < 10) {
            b[i] = i + '0';
        } else {
            b[i] = i - 10 + 'A';
        }
    }
    printf("%c%c%c%c\n", b[12], b[0], b[13], b[14]);
}

void array_randneg(int a[], int size)
{
    int i;
    for (i = 0; i < size; ++i) {
        a[i] = -rand();
    }
}

int array_isneg(int a[], int size)
{
    int isneg = 1;
    int i;
    for (i = 0; i < size; ++i) {
        isneg &= a[i] < 0;
        /* if(a[i] >= 0) return 0; */
    }
    return isneg;
    /* return 1; */
}

int main(void)
{
    int arr[3];
    srand(time(NULL));

    printf("\n    Aufgabe 3.1 a)\n");
    aufg_31a();
    printf("\n    Aufgabe 3.1 b)\n");
    aufg_31b();
    printf("\n    Aufgabe 3.2 a)\n");
    aufg_32a();
    printf("\n    Aufgabe 3.2 b)\n");
    aufg_32b();
    printf("\n    Aufgabe 3.3 a)\n");
    aufg_33a();
    printf("\n    Aufgabe 3.3 b)\n");
    aufg_33b();
    printf("\n    Aufgabe 3.4 a)\n");
    aufg_34a();
    printf("\n    Aufgabe 3.4 b)\n");
    aufg_34b();
    printf("\n    Aufgabe 3.5 a)\n");
    array_randneg(arr, 3);
    printf("%i %i %i\n", arr[0], arr[1], arr[2]);
    printf("\n    Aufgabe 3.5 b)\n");
    printf("%i\n", array_isneg(arr, 3));
    arr[0] = 0;
    printf("%i\n", array_isneg(arr, 3));
    
    return 0;
}
