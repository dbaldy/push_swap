#include "checker.h"

static void	add_line(char **aggregate, char *line)
{
	char	*old_ptr;

	old_ptr = *aggregate;
	if (*aggregate == NULL)
		*aggregate = ft_strdup(line);
	else
	{
		*aggregate = ft_strjoin_multiple(3, old_ptr, " ", line);
		free(old_ptr);
	}
}

char		**read_input(void)
{
	char	*line;
	char	*aggregate;
	char	**output;

	output = NULL;
	aggregate = NULL;
	while (get_next_line(0, &line))
	{
		add_line(&aggregate, line);
	}
	if (aggregate != NULL)
	{
		output = ft_strsplit(aggregate, SPACE);
		free(aggregate);
	}
	return (output);
}
