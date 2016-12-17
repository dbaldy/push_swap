/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:24:26 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:24:27 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void		destruct_pile(t_pile **pile)
{
	t_pile	*buf_pile;

	buf_pile = *pile;
	free(buf_pile->list);
	free(buf_pile);	
	*pile = NULL;
}
