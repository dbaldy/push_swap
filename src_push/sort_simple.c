#include "push_swap.h"

static int	get_index(t_pile *pile, int elem)
{
	int	through;

	through = 0;
	while (through < pile->count)
	{
		if (pile->list[through] == elem)
			return (through);
		through++;
	}
	error(SOLVE_ERR);
	return (-1);
}

static int	place_elem(t_pile *pile, t_pile *visuel, int direction,
	int elem)
{
	int	sens;
	int	distance;

	if (direction > 0)
		distance = get_distance(elem, 1, pile->count);
	else
		distance = get_distance(elem, 0, pile->count);
	sens = abs(distance);
	while (sens--)
	{
		if (distance < 0)
			reverse_rotate(pile, visuel, FALSE);
		else
			rotate(pile, visuel, FALSE);
	}
	return (0);
}

static int	reorder(t_pile *pile, t_pile *visuel, int distance)
{
	int		iter;

	iter = abs(distance);
	if (distance < 0 && iter != 1)
		iter--;
	while (iter--)
	{
		swap(pile, visuel, FALSE);
		if (iter == 0)
			break;
		if (distance > 0)
			reverse_rotate(pile, visuel, FALSE);
		else
			rotate(pile, visuel, FALSE);
	}
	return (1);
}

int		sort_simple(t_pile *pile, t_pile *visuel, int *sorted_list)
{
	int		min;
	int		elem;
	int		distance;
	int		place;

	pile->token++;
	if (pile->token >= pile->count)
		return (0);
	min = get_index(pile, pile->min);
	elem = get_index(pile, sorted_list[pile->token]);
	place = (min + pile->token >= pile->count) ? min + pile->token -
	pile->count : min + pile->token;
	distance = get_distance(elem, place, pile->count);
/*	ft_printf("place:%d elem:%d sorted_list[token]:%d distance:%d\n",
	place, elem,
	sorted_list[pile->token], distance);
*/	if (distance == 0)
		return (1);
	place_elem(pile, visuel, distance, elem);
	reorder(pile, visuel, distance);
	return (1);
}
