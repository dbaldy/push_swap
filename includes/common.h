#ifndef COMMON_H
# define COMMON_H
# include <stdio.h>
# include "struct.h"
# include "libft.h"
# include "ft_printf.h"

# define TRUE 1
# define FALSE 0
# define NO_ARGUMENT 1
# define INT_SIZE_MAX 11

# define USAGE_ERR 0
# define SOLVE_ERR 1
# define MEM_ERR 2
# define DUB_ERR 3
# define NB_ERR 4

# define PUSH_A "pa"
# define PUSH_B "pb"
# define SWAP_A "sa"
# define SWAP_B "sb"
# define SWAP_BOTH "ss"
# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define ROTATE_BOTH "rr"
# define REVERSE_ROTATE_A "rra"
# define REVERSE_ROTATE_B "rrb"
# define REVERSE_ROTATE_BOTH "rrr"

void	error(int errno);
int	check_arguments(char **argv);
int	is_numeric(char *arg);
int	is_int(char *arg);
int	solve(char **argv, int argc);
t_pile	*init_pile(char **argv, int argc, char id);
void	destruct_pile(t_pile **pile);
void	print_piles(t_pile *pile_a, t_pile *pile_b);
int	push(t_pile *pile_depart, t_pile *pile_arrival);
int	max(int a, int b);
int	min(int a, int b);
int	abs(int a);
void	check_dubs(t_pile *pile);
int	*int_cpy(int *dst, int *src, int src_size);
int	push_up(int *list, int count);
int	push_down(int *list, int count);
int	swap(t_pile *pile, t_pile *visuel, int both);
int	swap_both(t_pile *pile_a, t_pile *pile_b);
int	rotate(t_pile *pile, t_pile *visuel, int both);
int	rotate_both(t_pile *pile_a, t_pile *pile_b);
int	reverse_rotate(t_pile *pile, t_pile *visuel, int both);
int	reverse_rotate_both(t_pile *pile_a, t_pile *pile_b);
void	check_dubs(t_pile *pile);
void	read_options(char ***argv, int *argc);
int	option_v(int set);
int	option_c(int set);
int	max_table(int *table, int size);
int	min_table(int *table, int size);
void	free_table(char **list_operation);
int	is_push_swap();
void	print_int(int *list, int count);
#endif
