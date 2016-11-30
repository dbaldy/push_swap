#include "push_swap.h"

static int *get_distance_from_sol(t_pile *pile, int (*cmp)(int, int))
{
	int	*sorted_list;
	int	*distance_from_sol;

	if ((sorted_list = malloc(sizeof(int) * pile->count)) == NULL)
		error(1);
	int_cpy(sorted_list, pile->list, pile->count);
	quicksort(sorted_list, 0, pile->count - 1, cmp);
	distance_from_sol = calculate_distance(pile->list, 	
	sorted_list, pile->count);
	free(sorted_list);
	return (distance_from_sol);
}

int	is_distance_unique(t_pile *pile, int *distance, int (*cmp)(int, int))
{
	int	found_distance;
	int	index;
	int	*distance_from_sol;

	distance_from_sol = get_distance_from_sol(pile, cmp);
	index = 0;
	found_distance = distance_from_sol[index];
	while (index < pile->count)
	{
		if (found_distance != distance_from_sol[index])
			return (FALSE);
		found_distance = distance_from_sol[index];
		index++;
	}
	*distance = found_distance;
	free(distance_from_sol);
	return (TRUE);
}

static int	is_swap_needed(t_pile *pile)
{
	return (pile->list[0] > pile->list[1]) ? TRUE : FALSE;
}

int		prepare_for_pivot(t_pile *pile_a, t_pile *pile_b)
{
	int	distance;

	if (is_distance_unique(pile_a, &distance, is_crescent))
	{
		roll_pile(pile_a, pile_b, distance);
		return (FALSE);
	}
	else if (is_swap_needed(pile_a))
	{
		swap(pile_a, pile_b, FALSE);
		return (prepare_for_pivot(pile_a, pile_b));
	}
	return (TRUE);
}
