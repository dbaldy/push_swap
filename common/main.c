#include "common.h"

int		main(int argc, char **argv)
{
	if (argc == NO_ARGUMENT)
		return (0);
	argv++;
	read_options(&argv, &argc);
	if (check_arguments(argv))
		error(USAGE_ERR);
	if (!solve(argv, argc - 1))
		error(SOLVE_ERR);
	return (0);
}
