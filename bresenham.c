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


//regarder la video : https://youtu.be/nQbnYl7xgb8

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
	bresen.Xincr = 1;
	bresen.Yincr = 1;

	return(bresen);
}

void	bresenham_finder(t_coord *coords, t_coord *coords_nxt, t_params *param)
{
	t_bres		bresen;

	bresen = bresenham_init(coords, coords_nxt, param);

	if (bresen.x0 > bresen.x1)
		bresen.Xincr = -1;
	if (bresen.y0 > bresen.y1)
		bresen.Yincr = -1;
	if (bresen.dex >= bresen.dey)
	{
		while (bresen.i <= bresen.dex)
		{
			if (bresen.x0 < WIDTH && bresen.y0 < HIGHT && bresen.x0 > 0 && bresen.y0 > 0)
				param->bres_tab[bresen.x0][bresen.y0] = 0xFFFFFF;
			bresen.i++;
			bresen.x0 += bresen.Xincr;
			bresen.ex -= bresen.dy;
			if (bresen.ex < 0)
			{
				bresen.y0 += bresen.Yincr;
				bresen.ex += bresen.dx;
			}
		}
	}
	if (bresen.dex < bresen.dey)
	{
		while (bresen.i <= bresen.dey)
		{
			if (bresen.x0 < WIDTH && bresen.y0 < HIGHT && bresen.x0 > 0 && bresen.y0 > 0)
				param->bres_tab[bresen.x0][bresen.y0] = 0xFFFFFF;
			bresen.i++;
			bresen.y0 += bresen.Yincr;
			bresen.ey -= bresen.dx;
			if (bresen.ey < 0)
			{
				bresen.x0 += bresen.Xincr;
				bresen.ey += bresen.dy;
			}
		}
	}
}