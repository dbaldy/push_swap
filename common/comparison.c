/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:24:19 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:24:20 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		is_descent(int a, int b)
{
	return (a >= b) ? TRUE : FALSE;
}

int		is_crescent(int a, int b)
{
	return (a <= b) ? TRUE : FALSE;
}
