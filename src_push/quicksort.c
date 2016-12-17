/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:23:11 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:23:13 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swp(int *a, int *b)
{
	int swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

static int	partition(int *list, int lo, int hi, int (*cmp)(int, int))
{
	int	pivot;
	int	i;
	int	j;

	pivot = list[hi];
	i = lo;
	j = lo;
	while (j < hi)
	{
		if (cmp(list[j], pivot))
		{
			swp(&(list[i]), &(list[j]));
			i++;
		}
		j++;
	}
	swp(&(list[i]), &(list[hi]));
	return (i);
}

int		*quicksort(int *list, int lo, int hi, int (*cmp)(int, int))
{
	int	p;

	if (lo < hi)
	{
		p = partition(list, lo, hi, cmp);
		quicksort(list, lo, p - 1, cmp);
		quicksort(list, p + 1, hi, cmp);
	}
	return (list);
}
