/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 22:33:32 by smortier          #+#    #+#             */
/*   Updated: 2018/02/12 22:33:34 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_coord *coord, void *mlx_ptr, void *win_ptr)
{
	while (coord)
	{
		if (coord->z)
			mlx_pixel_put(mlx_ptr, win_ptr, coord->x * 30 + 400, coord->y * 30
															+ 200, 0xFF00FF);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, coord->x * 30 + 400,
						coord->y * 30 + 200, 0xFFFFFF);
		coord = coord->next;
	}
}
