#include "push_swap.h"

int	equal_distance(t_pile *pile_a, t_pile *pile_b, int *distance)
{
	int	distance_a;
	int	distance_b;
	int	min_distance;

	if (is_distance_unique(pile_a, &distance_a, is_crescent) &&
		is_distance_unique(pile_b, &distance_b, is_descent))
	{
		if (distance_a > 0 && distance_b > 0)
			*distance = min(distance_a, distance_b);
		if (distance_a < 0 && distance_b < 0)
			*distance = max(distance_a, distance_b);
		return (TRUE);
	}
	return (FALSE);
}
