#include "stdlib.h"

int	*int_cpy(int *dst, int *src, int src_size)
{
	int	count;

	count = 0;
	while (count < src_size)
	{
		dst[count] = src[count];
		count++;
	}
	return (dst);
}
