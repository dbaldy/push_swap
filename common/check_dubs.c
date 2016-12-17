/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dubs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:24:11 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:24:13 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	insert_nb(t_dubs *indexed_list, int nb)
{
	int	*buf_list;

	if ((buf_list = malloc(sizeof(int) * (indexed_list->count + 1))) == NULL)
		error(MEM_ERR);
	buf_list = int_cpy(buf_list, indexed_list->list, indexed_list->count);
	buf_list[indexed_list->count] = nb;
	indexed_list->count++;
	if (indexed_list->list != NULL)
		free(indexed_list->list);
	indexed_list->list = buf_list;
}

static void	check_dub(t_dubs **hash, int nb, int prime)
{
	int	index;
	int	count;

	index = (nb > 0) ? nb % prime : -nb % prime;
	if ((hash[index])->count == 0)
		insert_nb(hash[index], nb);
	else
	{
		count = hash[index]->count;
		while (count--)
		{
			if (nb == hash[index]->list[count])
				error(DUB_ERR);
		}
		insert_nb(hash[index], nb);
	}
}

static void	init_hash(t_dubs **hash, int prime)
{
	int	count;

	count = 0;
	while (count < prime)
	{
		if ((*hash = malloc(sizeof(t_dubs))) == NULL)
			error(MEM_ERR);
		(*hash)->list = NULL;
		(*hash)->count = 0;
		hash++;
		count++;
	}
}

static void	destruct_hash(t_dubs **hash, int prime)
{
	int	count;

	count = 0;
	while (count < prime)
	{
		if ((*hash)->list != NULL)
			free((*hash)->list);
		if (*hash != NULL)
			free(*hash);
		hash++;
		count++;
	}
}

void		check_dubs(t_pile *pile)
{
	t_dubs	**hash;
	int	prime;
	int	index;

	prime = ft_find_next_prime(pile->count);
	if ((hash = malloc(sizeof(t_dubs*) * prime)) == NULL)
		error(MEM_ERR);
	init_hash(hash, prime);	
	index = 0;
	while (index < pile->count)
	{
		check_dub(hash, pile->list[index], prime);	
		index++;
	}
	destruct_hash(hash, prime);
	free(hash);
}
