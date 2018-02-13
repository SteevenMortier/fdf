/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 23:06:06 by smortier          #+#    #+#             */
/*   Updated: 2018/01/29 23:06:07 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_params	*fill_params(t_coord *coords)
{
	t_coord		*temp;
	int			max_x;
	int			max_y;
	t_params	*newparam;

	temp = coords;
	max_x = 0;
	max_y = 0;
	while (temp)
	{
		if (temp->x >= max_x)
			max_x = temp->x;
		if (temp->y >= max_y)
			max_y = temp->y;
		temp = temp->next;
	}
	if (!(newparam = (t_params *)ft_memalloc(sizeof(t_params))))
		return (NULL);
	newparam->coords = coords;
	newparam->max_hori_win = max_x;
	newparam->max_vert_win = max_y;
	newparam->zoom = 30;
	newparam->speed = 1;
	newparam->mlx_ptr = NULL;
	newparam->win_ptr = NULL;
	return (newparam);
}
