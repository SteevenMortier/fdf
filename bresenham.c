/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 02:05:24 by smortier          #+#    #+#             */
/*   Updated: 2018/02/13 02:05:29 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bres	bresenham_init(t_coord *coords, t_coord *coords_nxt, t_params *param)
{
	t_bres bresen;

	bresen.x0 = coords->prt_x * param->zoom + param->lag_x;
	bresen.y0 = coords->prt_y * param->zoom + param->lag_y;
	bresen.x1 = coords_nxt->prt_x * param->zoom + param->lag_x;
	bresen.y1 = coords_nxt->prt_y * param->zoom + param->lag_y;
	bresen.ex = ABS(bresen.x1 - bresen.x0);
	bresen.ey = ABS(bresen.y1 - bresen.y0);
	bresen.dx = 2 * bresen.ex;
	bresen.dy = 2 * bresen.ey;
	bresen.dex = bresen.ex;
	bresen.dey = bresen.ey;
	bresen.i = 0;
	bresen.xincr = 1;
	bresen.yincr = 1;
	return (bresen);
}

void	norm_helper(t_params *param, t_bres bresen, t_coord *coords)
{
	if (bresen.dex < bresen.dey)
	{
		while (bresen.i <= bresen.dey)
		{
			if (bresen.x0 < WIDTH && bresen.y0 < HIGHT && bresen.x0 > 0 &&
				bresen.y0 > 0)
				param->bres_tab[bresen.x0][bresen.y0] = color(coords->z);
			bresen.i++;
			bresen.y0 += bresen.yincr;
			bresen.ey -= bresen.dx;
			if (bresen.ey < 0)
			{
				bresen.x0 += bresen.xincr;
				bresen.ey += bresen.dy;
			}
		}
	}
}

void	bresenham_finder(t_coord *coords, t_coord *coords_nxt, t_params *param)
{
	t_bres		bresen;

	bresen = bresenham_init(coords, coords_nxt, param);
	bresen.xincr = (bresen.x0 > bresen.x1) ? -1 : bresen.xincr;
	bresen.yincr = (bresen.y0 > bresen.y1) ? -1 : bresen.yincr;
	if (bresen.dex >= bresen.dey)
	{
		while (bresen.i <= bresen.dex)
		{
			if (bresen.x0 < WIDTH && bresen.y0 < HIGHT &&
					bresen.x0 > 0 && bresen.y0 > 0)
			{
				param->bres_tab[bresen.x0][bresen.y0] = color(coords->z);
			}
			bresen.i++;
			bresen.x0 += bresen.xincr;
			bresen.ex -= bresen.dy;
			if (bresen.ex < 0)
			{
				bresen.y0 += bresen.yincr;
				bresen.ex += bresen.dx;
			}
		}
	}
	norm_helper(param, bresen, coords);
}
