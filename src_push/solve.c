#include "push_swap.h"

static int	find_place(int elem, t_pile *pile)
{
	int	index;

	index = 0;
	while (index < pile->count)
	{
		if (pile->cmp(elem, pile->list[index]))
			break;
		index++;
	}
	return ((index == 0) ? 0 : index - 1);
}

static int	is_swap_needed(t_pile *pile)
{
	if (pile->count < 2)
		return (FALSE);
	return (!pile->cmp(pile->list[0], pile->list[1]));
}

static int	push_reordered_b(t_pile *pile_a, t_pile *pile_b)
{
	int	place;
	int	sens;
	int	distance;

	place = find_place(pile_a->list[0], pile_b);
	distance = get_distance(place, 0, pile_b->count);
	ft_printf("place: %d distance: %d\n", place, distance);
	sens = abs(distance);
	while (sens--)
	{
		if (distance < 0)
			reverse_rotate(pile_b, pile_a, FALSE);
		else
			rotate(pile_b, pile_a, FALSE);
	}
	push(pile_a, pile_b);
	return (0);
	is_swap_needed(pile_a);
}

static int	sort(t_pile *pile_a, t_pile *pile_b)
{
//	while (sort_simple(pile_a, pile_b, sorted_list))
//		;
	while (!is_empty(pile_a))
		push_reordered_b(pile_a, pile_b);
	while (!is_empty(pile_b))
		push(pile_b, pile_a);
	return (0);
}

int		solve(char **argv, int argc)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = init_pile(argv, argc, 'a');
	check_dubs(pile_a);
	pile_b = init_pile(NULL, argc, 'b');
	sort(pile_a, pile_b);
	destruct_pile(&pile_a);
	destruct_pile(&pile_b);
	return (TRUE);
}
