/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:27:28 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:27:29 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	solve(char **argv, int argc)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	char	**list_operation;

	pile_a = init_pile(argv, argc, 'a');
	check_dubs(pile_a);
	pile_b = init_pile(NULL, argc, 'b');
	list_operation = read_input();
	execute(list_operation, pile_a, pile_b);
	if (option_v(FALSE))
		print_piles(pile_a, pile_b);
	check_sorted(pile_a, pile_b);
	destruct_pile(&pile_a);
	destruct_pile(&pile_b);
	return (TRUE);
}
