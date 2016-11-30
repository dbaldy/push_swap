#include "common.h"

int		is_int(char *arg)
{
	int	first_number;
	int	output;
	char	*back_to_str;
	
	first_number = ft_atoi(arg);
	back_to_str = ft_itoa(first_number);
	if (ft_strcmp(arg, back_to_str) != 0)
		output = FALSE; 
	else
		output = TRUE;
	free(back_to_str);
	return output;
}
