#include "common.h"

static int	fill_list(char **argv, int *list)
{
	int	list_index;

	if (argv == NULL)
		return (FALSE);
	list_index = 0;
	while (*argv)
	{
		list[list_index] = ft_atoi(*argv);
		list_index++;
		argv++;
	}
	return (TRUE); 
}

static int	get_extr(t_pile *pile)
{
	if (pile->count > 0)
	{
		pile->max = max_table(pile->list, pile->count);
		pile->min = min_table(pile->list, pile->count);
	}
	return (0);
}

int		get_extremum(t_pile *pile_a, t_pile *pile_b)
{
	get_extr(pile_a);
	get_extr(pile_b);
	return (0);
}

t_pile		*init_pile(char **argv, int argc, char id)
{
	t_pile	*pile;

	if ((pile = malloc(sizeof(t_pile))) == NULL)
		error(MEM_ERR);
	if ((pile->list = malloc(sizeof(int) * argc)) == NULL)
		error(MEM_ERR);
	fill_list(argv, pile->list);
	if (argv != NULL)
		pile->count = argc;
	else
		pile->count = 0;
	pile->id = id;
	pile->token = 0;
	get_extr(pile);
	pile->cmp = (id == 'a') ? is_crescent : is_descent;
	return (pile);
}
