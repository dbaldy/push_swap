#include "push_swap.h"

int		get_distance(POINT depart, POINT arrival, int count)
{
	int	distance_up;
	int	distance_down;

	if (depart == arrival)
		return (0);
	if (depart < arrival)
	{
		distance_up = depart - arrival;
		distance_down = depart + count - arrival;
	}
	else
	{
		distance_up = - count - arrival + depart;
		distance_down = -arrival + depart;
	}
	return (abs(distance_down) < abs(distance_up)) ? distance_down :
	distance_up;
}

static int	*get_delta(int *list, int *sorted_list, int count)
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
	output = get_delta(list, sorted_list, count);
	return (output);
}
