/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:26:58 by dbaldy            #+#    #+#             */
/*   Updated: 2016/12/17 18:47:00 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "common.h"
# define POINT int
# define SWP 0
# define RO 1
# define RR 2
# define UNKNOWN 3

int	*quicksort(int *list, int lo, int hi, int (*cmp)(int, int));
int	prepare_for_pivot(t_pile *pile_a, t_pile *pile_b);
int	sort_both(t_pile *pile_a, t_pile *pile_b);
int	push_back_b(t_pile *pile_a, t_pile *pile_b);
int	roll_pile(t_pile *pile, t_pile *visuel, int index);
int	*calculate_distance(int *list, int *sorted_list, int count);
int	get_distance(POINT a, POINT b, int count);
int	push_back(t_pile *pile_a, t_pile *pile_b);
int	operate(t_pile *pile_a, t_pile *pile_b);
int	is_distance_unique(t_pile *pile, int *distance, int (*cmp)(int, int));
int	sort_simple(t_pile *pile, t_pile *visuel, int *sorted_list);
int	roll_both(t_pile *pile_a, t_pile *pile_b, int direction);
int	define_operation(t_pile *pile);
int	roll_top(t_pile *pile_a, t_pile *pile_b, int distance);
int	is_sorted(t_pile *pile);
int	is_empty(t_pile *pile);
int	cascade_pivot(t_pile *pile_a, t_pile *pile_b, int *sorted_list);
int	sort_next_unsorted(t_pile *pile, t_pile *visuel);
int	is_extremum(t_pile *pile, int index);
int	reorder_b(t_pile *pile_a, t_pile *pile_b, int elem);
int	find_index(int elem, t_pile *pile);

#endif
