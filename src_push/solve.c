#include "push_swap.h"

static int	sort(t_pile *pile_a, t_pile *pile_b)
{
	int	*distance_from_sol;
	int	*sorted_list;
	
	if ((sorted_list = malloc(sizeof(int) * pile_a->count)) == NULL)
		error(1);
	int_cpy(sorted_list, pile_a->list, pile_a->count);
	quicksort(sorted_list, 0, pile_a->count - 1, is_crescent);
	distance_from_sol = calculate_distance(pile_a->list,
	sorted_list, pile_a->count);
	if (prepare_for_pivot(pile_a, pile_b))
	{
		pivot(pile_a, pile_b, sorted_list);
		sort_both(pile_a, pile_b);
	}
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
