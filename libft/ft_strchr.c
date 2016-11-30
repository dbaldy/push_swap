/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:55:49 by cbaldy            #+#    #+#             */
/*   Updated: 2016/04/30 15:26:36 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		k;

	k = 0;
	while (s[k])
	{
		if (s[k] == c)
			return (&((char *)s)[k]);
		k++;
	}
	if (c == 0)
		return (&((char *)s)[k]);
	else
		return (NULL);
}
