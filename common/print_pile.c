#include "common.h"

static int	int_size(int nb)
{
	int	size;
	
	size = (nb <= 0) ? 1 : 0;
	while (nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static int	print_spaces(int nb_first, int nb_second)
{
	int	size_first;
	int	size_second;
	int	nb_spaces;

	size_first = int_size(nb_first);
	size_second = int_size(nb_second);
	nb_spaces = max(size_second - size_first, 0);
	while (nb_spaces--)
		ft_printf(" ");
	return (0);
}

void		print_single_pile(t_pile *first, t_pile *second)
{
	int	index;

	index = 0;
	ft_printf("%c: ", first->id);
	while (index < first->count)
	{
		ft_printf("%d ", first->list[index]);
		if (index < second->count)
			print_spaces(first->list[index], second->list[index]);
		index++;
	}
	ft_printf("\n");
}

void		print_piles(t_pile *first_pile, t_pile *second_pile)
{
	t_pile		*pile_a;
	t_pile		*pile_b;

	if (first_pile->id == 'a')
	{
		pile_a = first_pile;
		pile_b = second_pile;
	}
	else
	{
		pile_a = second_pile;
		pile_b = first_pile;
	}
	ft_printf("\n");
	print_single_pile(pile_a, pile_b);
	print_single_pile(pile_b, pile_a);
}
