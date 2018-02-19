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

void		calibrate(t_params *param, int caliber)
{
	t_coord		*coord;

	coord = param->coords;
	while (coord)
	{
		if (caliber + param->max_hori_win / 3 < param->max_hori_win)
		{
			coord->prt_x += caliber + param->max_hori_win / 3;
			coord->prt_y += param->max_vert_win / 3;
		}
		coord = coord->next;
	}
}

void		isometrique_proj(t_params *param)
{
	t_coord		*coord;
	float			minx;

	coord = param->coords;
	minx = 0;
	while (coord)
	{
		coord->prt_x = (sqrt(2) / 2) * ((float)coord->x - (float)coord->y);
		coord->prt_y = (float)((sqrt(2 / 3) * coord->z) +
				(float)((1 / sqrt(6)) *
				(float)(coord->x + coord->y)));
		coord->prt_y -= (float)coord->z / 20;
		minx = (coord->prt_x <= minx) ? coord->prt_x : minx;
		coord = coord->next;
	}
	if (minx < 0) //mars marche plus a cause de ca
		calibrate(param, minx * -1);
}

void		rotatation(t_params *param, int angle)
{
	t_coord		*coord;

	coord = param->coords;
	while (coord)
	{
		coord->prt_x = (coord->x * cos(angle)) - (coord->y * sin(angle));
		coord->prt_y = (coord->x * sin(angle)) + (coord->y * cos(angle));
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
		if (coord->next && coord->x != param->max_hori_win)
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
