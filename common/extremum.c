/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:24:32 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 17:42:42 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	abs(int a)
{
	return (a < 0) ? -a : a;
}

int	max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	min(int a, int b)
{
	return ((a < b) ? a : b);
}

int	max_table(int *table, int size)
{
	int	res;

	if (size < 1)
		error(SOLVE_ERR);
	res = table[0];
	while (size--)
	{
		res = max(table[size], res);
	}
	return (res);
}
	
int	min_table(int *table, int size)
{
	int	res;

	if (size < 1)
		error(SOLVE_ERR);
	res = table[0];
	while (size--)
	{
		res = min(table[size], res);
	}
	return (res);
}	
