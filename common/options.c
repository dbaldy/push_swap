/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:25:47 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:25:51 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	option_c(int set)
{
	static int	is_set;

	if (is_set == TRUE)
		return (TRUE);
	if (set == TRUE)
		is_set = TRUE;
	return (FALSE);
}

int	option_v(int set)
{
	static int	is_set;

	if (is_set == TRUE)
		return (TRUE);
	if (set == TRUE)
		is_set = TRUE;
	return (FALSE);
}

void	read_options(char ***ptr_argv, int *argc)
{
	char	**argv;

	argv = *ptr_argv;
	while (**argv == '-' && !is_numeric(*argv))
	{
		(*argc)--;
		(*argv)++;
		while (**argv == 'v' || **argv == 'c')
		{
			if (**argv == 'v')
				option_v(TRUE);
			else if (**argv == 'c')
				option_c(TRUE);
			(*argv)++;
		}
		if (**argv != '\0')
			error(USAGE_ERR);
		argv++;
	}
	*ptr_argv = argv;
}
