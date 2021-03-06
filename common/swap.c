/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:26:32 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:26:33 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	swap_both(t_pile *pile_a, t_pile *pile_b)
{
	swap(pile_a, pile_b, TRUE);
	swap(pile_b, pile_a, TRUE);
	if (is_push_swap())
	{
		ft_printf("ss\n");
		if (option_v(FALSE))
			print_piles(pile_a, pile_b);
	}
	return (0);
}

int	swap(t_pile *pile, t_pile *visuel, int both)
{
	int	swapper;

	swapper = pile->list[0];
	pile->list[0] = pile->list[1];
	pile->list[1] = swapper;
	if (!both && is_push_swap())
	{
		ft_printf("s%c\n", pile->id);	
		if (option_v(FALSE))
			print_piles(pile, visuel);
	}
	return (0);
}
