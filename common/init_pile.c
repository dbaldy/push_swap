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
	return (pile);
}
