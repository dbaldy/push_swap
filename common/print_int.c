/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:25:57 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:25:58 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_int(int *list, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		ft_printf("%d ", list[index]);
		index++;
	}
	ft_printf("\n");
}
