/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:20:27 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/18 16:25:12 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_reordered_b(t_pile *pile_a, t_pile *pile_b)
{
	int	elem;

	elem = pile_a->list[0];
	reorder_b(pile_a, pile_b, elem);
	push(pile_a, pile_b);
	return (0);
}

static int	reorder_a(t_pile *pile_a, t_pile *pile_b)
{
	int		min;
	int		index;
	int		distance;

	min = min_table(pile_a->list, pile_a->count);
	index = find_index(min, pile_a);
	distance = get_distance(index, 0, pile_a->count);
	roll_top(pile_a, pile_b, -distance);
	return (0);
}

static int	*get_sorted_list(t_pile *pile)
{
	int *list_cpy;
	int	*sorted_list;

	if ((list_cpy = malloc(sizeof(int) * pile->count)) == NULL)
			error(MEM_ERR);
	list_cpy = int_cpy(list_cpy, pile->list, pile->count); 
	sorted_list = quicksort(list_cpy, 0, pile->count - 1,
			pile->cmp);
	return (sorted_list);
}

static int	sort(t_pile *pile_a, t_pile *pile_b)
{
	int	*sorted_list;

	if (pile_a->count < 10)
	{
		sorted_list = get_sorted_list(pile_a);
		while (sort_simple(pile_a, pile_b, sorted_list))
			;
		reorder_a(pile_a, pile_b);
		free(sorted_list);
	}
	else if (!is_sorted(pile_a))
	{
		while (!is_empty(pile_a))
			push_reordered_b(pile_a, pile_b);
		while (!is_empty(pile_b))
			push(pile_b, pile_a);
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
