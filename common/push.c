#include "common.h"

int	push_up(int *list, int count)
{
	while (count)
	{
		list[count] = list[count - 1];
		count--;
	}
	return (0);
}

int	push_down(int *list, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		list[index] = list[index + 1];		
		index++;
	}
	return (0);
}

int	push(t_pile *pile_depart, t_pile *pile_arrival)
{
	if (pile_depart->count == 0)
		return (1);
	push_up(pile_arrival->list, pile_arrival->count);
	pile_arrival->list[0] = pile_depart->list[0];
	push_down(pile_depart->list, pile_depart->count);
	(pile_arrival->count)++;
	(pile_depart->count)--;
	if (is_push_swap())
		ft_printf("p%c ", pile_arrival->id);
	if (option_v(FALSE))
		print_piles(pile_depart, pile_arrival);
	return (0);
}
