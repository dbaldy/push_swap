#include "common.h"

int	check_arguments(char **argv)
{
	char	*trimmed;

	while (*argv)
	{
		trimmed = ft_strtrim(*argv);
		if (!is_numeric(trimmed) || !is_int(trimmed))
		{
			return (TRUE);
		}
		free(trimmed);
		argv++;
	}
	return (FALSE);
}
