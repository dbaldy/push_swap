#include "common.h"

int		is_descent(int a, int b)
{
	return (a >= b) ? TRUE : FALSE;
}

int		is_crescent(int a, int b)
{
	return (a <= b) ? TRUE : FALSE;
}
