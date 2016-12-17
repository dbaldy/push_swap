/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:25:20 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:25:21 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		is_int(char *arg)
{
	int	first_number;
	int	output;
	char	*back_to_str;
	
	first_number = ft_atoi(arg);
	back_to_str = ft_itoa(first_number);
	if (ft_strcmp(arg, back_to_str) != 0)
		output = FALSE; 
	else
		output = TRUE;
	free(back_to_str);
	return output;
}
