/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:25:27 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:25:33 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	first_digit_test(char c)
{
	if (ft_isdigit(c) || c == '+' || c == '-')
		return (TRUE);
	return (FALSE);
}

int		is_numeric(char *arg)
{
	if (!first_digit_test(*arg))
		return (FALSE);
	arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (FALSE);
		arg++;
	}
	return (TRUE);
}
