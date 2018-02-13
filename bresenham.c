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


void	bresenham(int x0,int y0,int x1,int y1, t_params *param)
{
	int x;
	int y = y0;
	int dx = x1 - x0;
	int dy = y1 - y0;
	int incrE = 2 * dy;
	int incrNE = 2 * (dy - dx);
	int e = 2 * dy - dx;
	for (x = x0; x <= x1 ; x++)
	{
//		AfficherPixel(x, y, valeur);
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0x00FF00);
		if(e >= 0)
		{
			y += 1;
			e += incrNE; /* pixel Nord-Est */
		}
		else
			e += incrE; /* pixel Est */
	}
	/* fin BresenhamEntier */
}

void	bresenham_other_case(int x0,int y0,int x1,int y1, t_params *param)
{
	int y;
	int x = x0;
	int dy = y1 - y0;
	int dx = x1 - x0;
	int incrE = 2 * dx;
	int incrNE = 2 * (dx - dy);
	int e = 2 * dx - dy;
	for (y = y0; y <= y1 ; y++)
	{
//		AfficherPixel(x, y, valeur);
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFF00FF);
		if(e >= 0)
		{
			x += 1;
			e += incrNE; /* pixel Nord-Est */
		}
		else
			e += incrE; /* pixel Est */
	}
	/* fin BresenhamEntier */
}

void	bresenham_finder(int x0,int y0,int x1,int y1, t_params *param)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int IncX, IncY;

	if (dx > 0)
		IncX = 1;
	else
	{
		IncX = -1;
		dx = -dx;
	}
	if(dy > 0)
		IncY = 1;
	else
	{
		IncY = -1;
		dy = -dy;
	}
	if(dx >= dy)
/* algorithme normal */
		bresenham(x0, y0, x1, y1, param);
	else
		bresenham_other_case(x0, y0, x1, y1, param);
/* inverser x et y dans l’algorithme */
}
