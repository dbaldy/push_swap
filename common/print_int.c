#include "common.h"

void	print_int(int *list, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		ft_printf("%d ", list[index]);
		index++;
	}
	ft_printf("\n");
}
