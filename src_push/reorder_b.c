/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:40:29 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 18:46:10 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest_elem_smaller_than(int elem, t_pile *pile)
{
	int		index;
	int		result;
	int		found;

	index = 0;
	found = 0;
	result = pile->list[0];
	while (index < pile->count)
	{
		if (pile->list[index] < elem && pile->list[index] > result)
		{
			result = pile->list[index];
			found = 1;
		}
		index++;
	}
	if (!found)
		return (max_table(pile->list, pile->count));
	return (result);
}

int			find_index(int top, t_pile *pile)
{
	int	index;

	index = 0;
	while (index < pile->count)
	{
		if (pile->list[index] == top)
			break;
		index++;
	}
	return (index);
}

int			reorder_b(t_pile *pile_a, t_pile *pile_b, int elem)
{
	int	top;
	int index;
	int distance;

	if (pile_b->count < 2)
		return (0);
	top = find_biggest_elem_smaller_than(elem, pile_b);
	index = find_index(top, pile_b);
	distance = get_distance(index, 0, pile_b->count);
	roll_top(pile_b, pile_a, -distance);
	return (0);
}
