/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:23:35 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 18:25:09 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_empty(t_pile *pile)
{
	return (pile->count == 0) ? TRUE : FALSE;
}

int		is_sorted(t_pile *pile)
{
	int	index;
	int	(*pilecmp)(int, int);

	if (pile->id == 'b' && is_empty(pile))
		return (TRUE);
	pilecmp = (pile->id == 'a') ? is_crescent : is_descent;
	index = 0;
	while (index < pile->count - 1)
	{
		if (!pilecmp(pile->list[index], pile->list[index + 1]))
			return (FALSE);	
		index++;
	}
	return (TRUE);
}

int		sort_both(t_pile *pile_a, t_pile *pile_b)
{
//	while (!is_sorted(pile_a) && !is_sorted(pile_b))
//		operate(pile_a, pile_b);
	while (!is_sorted(pile_a))
		sort_simple(pile_a, pile_b, NULL);
//	while (!is_sorted(pile_b))
//		sort_simple(pile_b, pile_a);
	return (0);
}
