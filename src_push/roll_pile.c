#include "push_swap.h"

static int	get_distance_to_top(int count, int index)
{
	return (get_distance(index, 0, count));
}

int		roll_pile(t_pile *pile, t_pile *visuel, int index)
{
	int distance;

	distance = get_distance_to_top(pile->count, index);
	if (distance < 0)
	{
		distance = -distance;
		while (distance--)
			reverse_rotate(pile, visuel, FALSE);
	}
	else
	{
		while (distance--)
			rotate(pile, visuel, FALSE);
	}
	return (FALSE);
}
