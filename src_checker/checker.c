#include "checker.h"

int	solve(char **argv, int argc)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	char	**list_operation;

	pile_a = init_pile(argv, argc, 'a');
	check_dubs(pile_a);
	pile_b = init_pile(NULL, argc, 'b');
	list_operation = read_input();
	execute(list_operation, pile_a, pile_b);
	print_piles(pile_a, pile_b);
	check_sorted(pile_a, pile_b);
	return (TRUE);
}
