#include "push_swap.h"

void	pivot(t_pile *pile_a, t_pile *pile_b, int *sorted_list)
{
	int	index;
	int	roll;
	int	pivot;

	index = 0;
	pivot = sorted_list[pile_a->count / 2];
	ft_printf("pivot:%d\n", pivot);
	while (index < pile_a->count)
	{
		if (pile_a->list[index] < pivot)
		{
			roll = get_distance(index, 0,
			pile_a->count);
			if (roll != 0)
				roll_pile(pile_a, pile_b, roll);
			push(pile_a, pile_b);
			index = 0;
		}
		else
			index++;
	}
}
