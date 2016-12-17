/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:27:34 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:27:35 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_operation(char *operation, t_pile *pile_a, t_pile *pile_b)
{
	if (ft_strcmp(PUSH_A, operation) == 0)
		push(pile_b, pile_a);
	else if (ft_strcmp(PUSH_B, operation) == 0)
		push(pile_a, pile_b);
	else if (ft_strcmp(SWAP_A, operation) == 0)
		swap(pile_a, pile_b, FALSE);
	else if (ft_strcmp(SWAP_B, operation) == 0)
		swap(pile_b, pile_a, FALSE);
	else if (ft_strcmp(SWAP_BOTH, operation) == 0)
		swap_both(pile_a, pile_b);
	else if (ft_strcmp(ROTATE_A, operation) == 0)
		rotate(pile_a, pile_b, FALSE);
	else if (ft_strcmp(ROTATE_B, operation) == 0)
		rotate(pile_b, pile_a, FALSE);
	else if (ft_strcmp(ROTATE_BOTH, operation) == 0)
		rotate_both(pile_a, pile_b);
	else if (ft_strcmp(REVERSE_ROTATE_A, operation) == 0)
		reverse_rotate(pile_a, pile_b, FALSE);
	else if (ft_strcmp(REVERSE_ROTATE_B, operation) == 0)
		reverse_rotate(pile_b, pile_a, FALSE);
	else if (ft_strcmp(REVERSE_ROTATE_BOTH, operation) == 0)
		reverse_rotate_both(pile_a, pile_b);
	else
	{
		ft_printf("unkown operation %s\n", operation);
		error(1);
	}
}

void		execute(char **list_operation, t_pile *pile_a, t_pile *pile_b)
{
	char	**iterator;

	iterator = list_operation;
	if (iterator == NULL)
		return ;
	while (*iterator)
	{
		exec_operation(*iterator, pile_a, pile_b);
		iterator++;
	}
}
