/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:26:41 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 16:26:42 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"
# define BUF_SIZE 1024
# define SPACE ' '

char	**read_input(void);
int	get_next_line(int fd, char **line);
void	execute(char **list_operation, t_pile *pile_a, t_pile *pile_b);
void	check_sorted(t_pile *pile_a, t_pile *pile_b);
#endif
