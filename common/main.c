/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:25:40 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:25:42 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		main(int argc, char **argv)
{
	if (argc == NO_ARGUMENT)
		return (0);
	argv++;
	read_options(&argv, &argc);
	if (check_arguments(argv))
		error(USAGE_ERR);
	if (!solve(argv, argc - 1))
		error(SOLVE_ERR);
	return (0);
}
