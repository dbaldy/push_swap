/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_couples.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:23:51 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:23:52 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_couples(int *distance_from_sol, t_pile *pile, t_pile *visuel)
{
	int	index;
	int	already_rolled;

	index = 0;
	already_rolled = 0;
	while (index < pile->count - 1)
	{
		if (pile->list[index] == 1 && pile->list[index + 1] == -1)
		{
			roll_pile(pile, visuel, index - already_rolled);
			swap(pile, visuel, FALSE);
			already_rolled = index;
		}
		index++;
	}
	return (FALSE);
}
