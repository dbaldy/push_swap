/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:27:04 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:27:05 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_pile
{
	int	*list;
	int	count;
	char	id;
	int	max;
	int	min;
	int	token;
	int	(*cmp)(int, int);
}		t_pile;

typedef struct	s_dubs
{
	int	*list;
	int	count;
}		t_dubs;

#endif
