/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:20:53 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:20:57 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "common.h"

void		error(int errno)
{
	ft_printf("Error!\n");
	if (errno == USAGE_ERR)
		ft_printf("usage: push_swap/checker [-vc] [int ...]\n");
	if (errno == SOLVE_ERR)
		ft_printf("An error occurred while sorting the list.\n");
	if (errno == MEM_ERR)
		ft_printf("An error occurred while allocating memory.\n");
	if (errno == DUB_ERR)
		ft_printf("A dub has been found.\n");
	exit(1);
}
