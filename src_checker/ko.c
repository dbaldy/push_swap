#include "common.h"

void	error(int errno)
{
	ft_printf("KO\n");
	exit(1);
	errno = 0;
}
