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
