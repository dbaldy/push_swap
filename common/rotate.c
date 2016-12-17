#include "common.h"

int	rotate_both(t_pile *pile_a, t_pile *pile_b)
{
	rotate(pile_a, pile_b, TRUE);
	rotate(pile_b, pile_a, TRUE);
	if (is_push_swap())
	{
		ft_printf("rr\n");
		if (option_v(FALSE))
			print_piles(pile_a, pile_b);
	}
	return (0);
}

int	rotate(t_pile *pile, t_pile *visuel, int both)
{
	int	swap;

	if (pile->count > 0)
	{
		swap = pile->list[0];
		push_down(pile->list, pile->count);
		pile->list[pile->count - 1] = swap;
	}
	if (!both && is_push_swap())
	{
		ft_printf("r%c\n", pile->id);
		if (option_v(FALSE))
			print_piles(pile, visuel);
	}
	return (0);
}
