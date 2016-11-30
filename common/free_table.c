#include "common.h"

void	free_table(char **list_operation)
{
	char **through;

	if (list_operation == NULL)
		return ;
	through = list_operation;
	while (*through)
	{
		free(through);
		through++;
	}
	free(list_operation);
}
