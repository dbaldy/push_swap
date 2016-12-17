/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:23:18 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:23:20 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_distance_to_top(int index, int count)
{
	return (get_distance(index, 0, count));
}


int		roll_both(t_pile *pile_a, t_pile *pile_b, int direction)
{
	if (direction < 0)
		reverse_rotate_both(pile_a, pile_b);
	else if (direction > 0)
		rotate_both(pile_a, pile_b);
	else
		return (FALSE);
	return (TRUE);
}

int		roll_pile(t_pile *pile, t_pile *visuel, int distance)
{
	if (distance < 0)
	{
		distance = -distance;
		while (distance--)
			reverse_rotate(pile, visuel, FALSE);
	}
	else
	{
		while (distance--)
			rotate(pile, visuel, FALSE);
	}
	return (FALSE);
}

int		roll_top(t_pile *pile, t_pile *visuel, int index)
{
	int	distance;

	distance = get_distance_to_top(index, pile->count);
	if (distance < 0)
	{
		distance = -distance;
		while (distance--)
			rotate(pile, visuel, FALSE);
	}
	else
	{
		while (distance--)
			reverse_rotate(pile, visuel, FALSE);
	}
	return (FALSE);
}
