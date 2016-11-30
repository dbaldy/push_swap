#include "push_swap.h"

int		get_distance(POINT a, POINT b, int count)
{
	int	distance_up;
	int	distance_down;

	if (a == b)
		return (0);
	distance_up = (a < b) ? b - a : count - a + b;
	distance_down = (a > b) ? b - a : -a + b - count;	
	return (abs(distance_down) < abs(distance_up)) ? distance_down :
	distance_up;
}

static int	*get_delta(int *sorted_list, int *list, int count)
{
	int	main_index;
	int	sub_index;
	int	*output;

	if ((output = malloc(sizeof(int) * count)) == NULL)
		error(1);
	main_index = 0;
	while (main_index < count)
	{
		sub_index = 0;
		while (list[main_index] != sorted_list[sub_index])
			sub_index++;
		output[main_index] = get_distance(sub_index, main_index, count);
		main_index++;
	}
	return (output);
}

int		*calculate_distance(int *list, int *sorted_list, int count)
{
	int	*output;

	if ((output = malloc(sizeof(int) * count)) == NULL)
		error(1);
	output = get_delta(sorted_list, list, count);
	return (output);
}
