#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "common.h"
# define POINT int

int	*quicksort(int *list, int lo, int hi, int (*cmp)(int, int));
int	prepare_for_pivot(t_pile *pile_a, t_pile *pile_b);
void	pivot(t_pile *pile_a, t_pile *pile_b, int *sorted_list);
int	sort_both(t_pile *pile_a, t_pile *pile_b);
int	push_back_b(t_pile *pile_a, t_pile *pile_b);
int	roll_pile(t_pile *pile, t_pile *visuel, int index);
int	*calculate_distance(int *list, int *sorted_list, int count);
int	get_distance(POINT a, POINT b, int count);
int	push_back(t_pile *pile_a, t_pile *pile_b);
int	is_crescent(int a, int b);
int	is_descent(int a, int b);
int	operate(t_pile *pile_a, t_pile *pile_b);
int	is_distance_unique(t_pile *pile, int *distance, int (*cmp)(int, int));
int	sort_simple(t_pile *pile);
#endif
