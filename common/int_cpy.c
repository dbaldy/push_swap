/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:25:14 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:25:15 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	*int_cpy(int *dst, int *src, int src_size)
{
	int	count;

	count = 0;
	while (count < src_size)
	{
		dst[count] = src[count];
		count++;
	}
	return (dst);
}
