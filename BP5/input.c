#include "input.h"
#include <stdio.h>
#include <float.h>

double read_double(void)
{
	int status;
	double value;
	char c;

	status = scanf("%lf", &value);
	if (status == EOF) {
		return DBL_MIN;
	} else if (status == 0) {
		if (!flush_buff()) {
			return DBL_MIN;
		}
		return DBL_MAX;
	}
	c = getchar();
	if (c == EOF) {
		return DBL_MIN;
	} else if (c != '\n') {
		if (!flush_buff()) {
			return DBL_MIN;
		}
		return DBL_MAX;
	}
	if (value == DBL_MIN || value == DBL_MAX) {
		return DBL_MAX;
	}
	return value;
}

int flush_buff(void)
{
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
	return c != EOF;
}
