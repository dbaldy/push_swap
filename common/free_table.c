/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:24:38 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:24:39 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	free_table(char **list_operation)
{
	char **through;

	if (list_operation == NULL)
		return ;
	through = list_operation;
	while (*through)
	{
		free(through);
		through++;
	}
	free(list_operation);
}
