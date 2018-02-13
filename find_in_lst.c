/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 21:53:20 by smortier          #+#    #+#             */
/*   Updated: 2018/02/12 21:53:26 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		*finded_down(t_coord *coord, int x, int y)
{
	while (coord)
	{
		if (coord->y == y + 1 && coord->x == x)
			return (coord);
		coord = coord->next;
	}
	return (NULL);
}

t_coord	*finded_diag(t_coord *coord, int x, int y)
{
	while (coord)
	{
		if (coord->y == y + 1 && coord->x == x + 1)
			return (coord);
		coord = coord->next;
	}
	return (NULL);
}
