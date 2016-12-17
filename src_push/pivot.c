/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:22:56 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:22:58 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot_values(int *sorted_list, int count, int *min, int *max)
{
	static int	occurrence;
	int		borne_max;


	if (occurrence * 20 >= count || count < 20)
		return (TRUE);
	borne_max = ((occurrence + 1) * 20 < count) ? (occurrence + 1) * 20
			: count - 1;
	if (count < 40)
	{
		*min = sorted_list[0];
		*max = sorted_list[count / 2];
	}
	else
	{
		*min = sorted_list[occurrence * 20];
		*max = sorted_list[borne_max];
		occurrence++;
	}
	return (FALSE);
}

int		replace_pile(t_pile *pile_a, t_pile *pile_b, int temoin)
{
	int	index;
	int	roll;

	index = 0;
	while (index < pile_a->count)
	{
		if (pile_a->list[index] == temoin)
		{
			roll = get_distance(index, 0, pile_a->count);
			if (roll != 0)
				roll_top(pile_a, pile_b, roll);
			return (0);
		}
		index++;
	}
	return (0);
}

static int	pivot(t_pile *pile_a, t_pile *pile_b, int min, int max)
{
	int	index;
	int	roll;

	index = 0;
	while (index < pile_a->count)
	{
		if (pile_a->list[index] >= min && pile_a->list[index] < max)
		{
			roll = get_distance(index, 0, pile_a->count);
			if (roll != 0)
				roll_top(pile_a, pile_b, roll);
			push(pile_a, pile_b);
			index = 0;
		}
		else
			index++;
	}
	return (0);
}
//TODO TEST CASCADE PIVOT!
// MODIFIED SORT_SIMPLE!
int		cascade_pivot(t_pile *pile_a, t_pile *pile_b, int *sorted_list)
{
	int	min;
	int	max;
	int	temoin;
	int	index;

	while (!get_pivot_values(sorted_list, pile_a->count, &min, &max))
	{
		index = 0;
		while (pile_a->list[index] >= min && pile_a->list[index] < max)
			index++;
		temoin = pile_a->list[index];
		pivot(pile_a, pile_b, min, max);
		replace_pile(pile_a, pile_b, temoin);
		get_extremum(pile_a, pile_b);
		while (!is_sorted(pile_b))
			sort_simple(pile_b, pile_a, NULL);
		while (!is_empty(pile_b))
			push(pile_b, pile_a);
	}
	return (0);
}
