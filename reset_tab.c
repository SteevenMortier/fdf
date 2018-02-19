#include "fdf.h"

void	reset_tab(t_params *param)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HIGHT)
			param->bres_tab[x][y] = 0;
	}
}
