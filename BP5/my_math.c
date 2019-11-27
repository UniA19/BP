#include <errno.h>
#include <stdio.h>
#include <float.h>

#include "my_math.h"

double my_pow(double x, int y)
{
        double power = 1.0;

        if (x == 0 && y < 0) {
                errno = EDOM;
                return 0.0; 
        }

        if (y < 0) power = 1.0 / my_pow(x, -y);

        if (y == 0) power = 1.0;

        if (y > 0) {
                int i;
                for (i = 0; i < y; ++i) {
                        power *= x;
                }
        }

        if (my_fabs(power) > DBL_MAX) {
                errno = ERANGE;
        }

        if(my_fabs(power) < DBL_MIN) {
                errno = ERANGE;
                return (power < 0) ? -0.0 : 0.0;
        }

        return power;
}
