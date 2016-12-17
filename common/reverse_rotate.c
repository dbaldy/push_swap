#include "common.h"

int	reverse_rotate_both(t_pile *pile_a, t_pile *pile_b)
{
	reverse_rotate(pile_a, pile_b, TRUE);
	reverse_rotate(pile_b, pile_a, TRUE);
	if (is_push_swap())
	{
		ft_printf("rrr\n");
		if (option_v(FALSE))
			print_piles(pile_a, pile_b);
	}
	return (0);
}

int	reverse_rotate(t_pile *pile, t_pile *visuel, int both)
{
	int	swap;

	if (pile->count > 0)
	{
		swap = pile->list[pile->count - 1];
		push_up(pile->list, pile->count - 1);
		pile->list[0] = swap;
	}
	if (!both && is_push_swap())
	{
		ft_printf("rr%c\n", pile->id);
		if (option_v(FALSE))
			print_piles(pile, visuel);
	}
	return (0);
}
