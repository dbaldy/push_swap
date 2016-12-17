/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:24:03 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:24:05 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	check_arguments(char **argv)
{
	char	*trimmed;

	while (*argv)
	{
		trimmed = ft_strtrim(*argv);
		if (!is_numeric(trimmed) || !is_int(trimmed))
		{
			return (TRUE);
		}
		free(trimmed);
		argv++;
	}
	return (FALSE);
}
