/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_holder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 22:43:13 by smortier          #+#    #+#             */
/*   Updated: 2018/02/12 22:44:38 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_holder_bis(int key, t_params *param)
{
	t_coord *coords;

	coords = param->coords;
	if (key == PAGE_UP || key == PAGE_DOWN)
	{
		while (coords)
		{
			if (coords->z)
			{
				coords->z = (key == PAGE_UP) ? coords->z + 1 : coords->z - 1;
				if (!coords->z)
					coords->z = (key == PAGE_UP) ? 1 : -1;
			}
			coords = coords->next;
		}
	}
	if (key == 24)
		param->zoom += 1;
	if (key == 27)
		param->zoom -= 1;
	mlx_destroy_image(param->mlx_ptr, param->img.img_ptr);
	reset_tab(param);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	prt_form(param);
	return (0);
}

int			key_holder(int key, t_params *param)
{
	t_coord *coords;

	coords = param->coords;
	if (param->last_key == key)
		param->speed += 0.5;
	else
		param->speed = 1;
	param->last_key = key;
	if (key == ESC)
		exit(0);
	if (key == ARROW_UP)
		param->lag_y -= 1 * param->speed;
	if (key == ARROW_DOWN)
		param->lag_y += 1 * param->speed;
	if (key == ARROW_LEFT)
		param->lag_x -= 1 * param->speed;
	if (key == ARROW_RIGHT)
		param->lag_x += 1 * param->speed;
	key_holder_bis(key, param);
	return (0);
}
