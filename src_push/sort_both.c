#include "push_swap.h"

int		is_descent(int a, int b)
{
	return (a >= b) ? TRUE : FALSE;
}

int		is_crescent(int a, int b)
{
	return (a <= b) ? TRUE : FALSE;
}

static int	is_empty(t_pile *pile)
{
	return (pile->count == 0) ? TRUE : FALSE;
}

static int	is_sorted(t_pile *pile)
{
	int	index;
	int	(*pilecmp)(int, int);

	if (pile->id == 'b' && is_empty(pile))
		return (TRUE);
	pilecmp = (pile->id == 'a') ? is_crescent : is_descent;
	index = 0;
	while (index < pile->count - 1)
	{
		if (!pilecmp(pile->list[index], pile->list[index + 1]))
			return (FALSE);	
		index++;
	}
	return (TRUE);
}

int		sort_both(t_pile *pile_a, t_pile *pile_b)
{
	if (is_sorted(pile_a))
		sort_simple(pile_b);
	else if (is_sorted(pile_b))
		sort_simple(pile_a);
	while (!is_sorted(pile_a) && !is_sorted(pile_b))
		operate(pile_a, pile_b);
	while (!is_empty(pile_b))
		push(pile_b, pile_a);
	return (0);
}
