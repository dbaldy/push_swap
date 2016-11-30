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
