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

t_params	*finded_down(t_params *param, float x, float y)
{
	while (param)
	{
		if (param->y == y + 1 && param->x == x)
			return (param);
		param = param->next;
	}
	return (NULL);
}

t_params	*finded_diag(t_params *param, float x, float y)
{
	while (param)
	{
		if (param->y == y + 1 && param->x == x + 1)
			return (param);
		param = param->next;
	}
	return (NULL);
}

void		line_and_diag(float x0, float y0, float x1, float y1, void *mlx_ptr, void *win_ptr, int z)
{
	float	dx = ABS(x1-x0), sx = x0 < x1 ? 1 : -1;
	float	dy = ABS(y1-y0), sy = y0 < y1 ? 1 : -1;
	float	err = (dx > dy ? dx : -dy) / 2, e2;

	while (x0 <= x1 && y0 <= y1)
	{
		if (z)
			mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xFF0000);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xFFFFFF);
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

void		line_vert(float x0, float y0, float x1, float y1, void *mlx_ptr, void *win_ptr, int z)
{
	float	dx = ABS(x1-x0), sx = x0 < x1 ? 1 : -1;
	float	dy = ABS(y1-y0), sy = y0 < y1 ? 1 : -1;
	float	err = (dx > dy ? dx : -dy) / 2, e2;

	while (x0 <= x1)
	{
		if (z)
			mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xFF0000);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xFFFFFF);
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

void		ft_put_pixel(t_params *param, void *mlx_ptr, void *win_ptr)
{
	while (param)
	{
		if (param->z)
			mlx_pixel_put(mlx_ptr, win_ptr, param->x * 30 + 400, param->y * 30 + 200, 0xFF00FF);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, param->x * 30 + 400, param->y * 30 + 200, 0xFFFFFF);
		param = param->next;
	}
}

void		isometrique_proj(t_params *param)
{
	while (param)
	{
		printf("\033[31mx = [%f], y = [%f], z = [%f]\033[0m\n", param->x, param->y, param->z);
		param->prt_x = (sqrt(2)/2) * (param->x - param->y); ///rotation sweg
		param->prt_y = ((sqrt(2/3) * param->z) + ((1/sqrt(6)) * (param->x + param->y)));
		param->prt_y -= param->z / 20;
		printf("x = [%f], y = [%f], z = [%f]\n", param->x, param->y, param->z);
		param = param->next;
	}
}

void		init_drawing(t_params *param)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_params	*down;
	t_params	*diag;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 2000, "Smortier_fdf");
//	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0xFF00FF, "coucou");
	isometrique_proj(param);
//	ft_put_pixel(param, mlx_ptr, win_ptr);
	while (param)
	{
		down = finded_down(param, param->x, param->y);
		diag = finded_diag(param, param->x, param->y);
		if (param->next)
			line_and_diag(param->prt_x * 40 + 400, param->prt_y * 40 + 400, param->next->prt_x * 40 + 400, param->next->prt_y * 40 + 400, mlx_ptr, win_ptr, param->z);
		if (down)
			line_vert(down->prt_x * 40 + 400, down->prt_y * 40 + 400, param->prt_x * 40 + 400, param->prt_y * 40 + 400, mlx_ptr, win_ptr, param->z);
		if (diag)
			line_and_diag(param->prt_x * 40 + 400, param->prt_y * 40 + 400, diag->prt_x * 40 + 400, diag->prt_y * 40 + 400, mlx_ptr, win_ptr, param->z);
		param = param->next;
	}
	mlx_loop(mlx_ptr);
}
