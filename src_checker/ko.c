/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ko.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:27:46 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:27:47 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	error(int errno)
{
	ft_printf("KO\n");
	exit(1);
	errno = 0;
}
