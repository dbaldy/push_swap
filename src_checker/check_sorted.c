/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:27:14 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:27:15 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_sorted(t_pile *pile_a, t_pile *pile_b)
{
	int	pile_index;

	if (pile_b->count != 0)
	{
		//TODO Remove Debug
		ft_printf("b isn't empty\n");
		error(1);
	}
	pile_index = 0;
	while (pile_index < pile_a->count - 1)
	{
		if (pile_a->list[pile_index] > pile_a->list[pile_index + 1])
		{
			ft_printf("a isn't sorted\n");
			error(1);
		}
		pile_index++;
	}
	ft_printf("OK\n");
}
