#include "common.h"

void		destruct_pile(t_pile **pile)
{
	t_pile	*buf_pile;

	buf_pile = *pile;
	free(buf_pile->list);
	free(buf_pile);	
	*pile = NULL;
}
