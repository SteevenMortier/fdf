/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 21:49:46 by smortier          #+#    #+#             */
/*   Updated: 2018/02/12 21:49:48 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		line_and_diag(t_params *param, t_coord *coords, t_coord *coord_nxt)
{
	float	x0 = coords->prt_x * param->zoom + param->lag_x;
	float	y0 = coords->prt_y * param->zoom + param->lag_y;
	float	x1 = coord_nxt->prt_x * param->zoom + param->lag_x;
	float	y1 = coord_nxt->prt_y * param->zoom + param->lag_y;
	float	dx = ABS(x1-x0), sx = x0 < x1 ? 1 : -1;
	float	dy = ABS(y1-y0), sy = y0 < y1 ? 1 : -1;
	float	err = (dx > dy ? dx : -dy) / 2;
	float	e2;

	while (x0 <= x1 && y0 <= y1)
	{
		if (coords->z || coord_nxt->z)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x0, y0, 0xFF0000);
		else
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void		line_vert(t_params *param, t_coord *coords, t_coord *coord_nxt)
{
	float	x1 = coords->prt_x * param->zoom + param->lag_x;
	float	y1 = coords->prt_y * param->zoom + param->lag_y;
	float	x0 = coord_nxt->prt_x * param->zoom + param->lag_x;
	float	y0 = coord_nxt->prt_y * param->zoom + param->lag_y;
	float	dx = ABS(x1-x0), sx = x0 < x1 ? 1 : -1;
	float	dy = ABS(y1-y0), sy = y0 < y1 ? 1 : -1;
	float	err = (dx > dy ? dx : -dy) / 2;
	float	e2;

	while (x0 <= x1 || (x0 <= x1 && y0 <= y1))
	{
		if (coords->z || coord_nxt->z)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x0, y0, 0xFF0000);
		else
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err;
		if (e2 >-dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}
