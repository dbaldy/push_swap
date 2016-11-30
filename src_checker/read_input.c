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
	char	buf[1024];
	char	*aggregate;
	char	**output;

	output = NULL;
	aggregate = NULL;
	ft_bzero(buf, 1024);
	while (read(0, buf, 1023) > 0)
	{
		add_line(&aggregate, buf);
	}
	if (aggregate != NULL)
	{
		output = ft_strsplit(aggregate, SPACE);
		free(aggregate);
	}
	return (output);
}
