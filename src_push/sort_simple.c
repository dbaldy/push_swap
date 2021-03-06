/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:23:43 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/18 16:10:38 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_pile *pile, int elem)
{
	int	through;

	through = 0;
	while (through < pile->count)
	{
		if (pile->list[through] == elem)
			return (through);
		through++;
	}
	error(SOLVE_ERR);
	return (-1);
}

static int	place_elem(t_pile *pile, t_pile *visuel, int direction,
	int elem)
{
	int	sens;
	int	distance;

	if (direction > 0)
		distance = get_distance(elem, 1, pile->count);
	else
		distance = get_distance(elem, 0, pile->count);
	sens = abs(distance);
	while (sens--)
	{
		if (distance < 0)
			reverse_rotate(pile, visuel, FALSE);
		else
			rotate(pile, visuel, FALSE);
	}
	return (0);
}

static int	reorder(t_pile *pile, t_pile *visuel, int distance)
{
	int		iter;

	iter = abs(distance);
	if (distance < 0 && iter != 1)
		iter--;
	while (iter--)
	{
		swap(pile, visuel, FALSE);
		if (iter == 0)
			break;
		if (distance > 0)
			reverse_rotate(pile, visuel, FALSE);
		else
			rotate(pile, visuel, FALSE);
	}
	return (1);
}

int		sort_simple(t_pile *pile, t_pile *visuel, int *sorted_list)
{
	int		extremum;
	int		elem;
	int		distance;
	int		place;

	pile->token++;
	if (pile->token >= pile->count)
		return (0);
	extremum = get_index(pile, pile->id == 'a' ? pile->max : pile->min);
	elem = get_index(pile, sorted_list[pile->token]);
	place = (extremum + pile->token >= pile->count) ? extremum + pile->token -
	pile->count : extremum + pile->token;
	distance = get_distance(elem, place, pile->count);
	if (distance == 0)
		return (1);
	place_elem(pile, visuel, distance, elem);
	reorder(pile, visuel, distance);
	return (1);
}
