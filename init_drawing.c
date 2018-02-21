/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:54:00 by smortier          #+#    #+#             */
/*   Updated: 2018/01/25 21:54:01 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometrique_proj(t_params *param)
{
	t_coord		*coord;
	float			minx;

	coord = param->coords;
	minx = 0;
	while (coord)
	{
		coord->prt_x = (sqrt(2) / 2) * ((float)coord->x - (float)coord->y);
		coord->prt_y = (float)((sqrt(2 / 3) * (float)coord->z) +
				(float)((1 / sqrt(6)) *
				(float)(coord->x + coord->y)));
		coord->prt_y -= (float)coord->z / 2;
		minx = (coord->prt_x <= minx) ? coord->prt_x : minx;
		coord = coord->next;
	}
}

void		prt_form(t_params *param)
{
	t_coord		*coord;
	t_coord		*down;
	t_coord		*diag;

	isometrique_proj(param);
	coord = param->coords;
	while (coord)
	{
		down = finded_down(coord, coord->x, coord->y);
		diag = finded_diag(coord, coord->x, coord->y);
		if (coord->next && coord->next->x)
			bresenham_finder(coord, coord->next, param);
		if (down)
			bresenham_finder(coord, down, param);
		if (diag)
			bresenham_finder(coord, diag, param);
		coord = coord->next;
	}
	ft_draw_image(param);
}

void		init_drawing(t_params *param)
{
	t_coord		*coord;
	int			index;

	index  = -1;
	param->init = 1;
	coord = param->coords;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr,
									WIDTH,
									HIGHT,
									"Smortier_fdf");
	param->bres_tab = ft_memalloc(sizeof(int *) * WIDTH);
	while (++index < WIDTH)
		param->bres_tab[index] = ft_memalloc(sizeof(int) * HIGHT);
	isometrique_proj(param);
	prt_form(param);
	mlx_hook(param->win_ptr, 2, 0, key_holder, param);
	mlx_loop(param->mlx_ptr);
}
