/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 11:05:24 by smortier          #+#    #+#             */
/*   Updated: 2018/03/03 11:05:27 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color(int alt)
{
	if (alt > 0)
	{
		if (alt <= 3)
			return (0x1caa1c);
		else if (alt <= 6)
			return (0xdcd700);
		else if (alt <= 9)
			return (0xc89121);
		else if (alt <= 12)
			return (0xa6741e);
		else if (alt <= 15)
			return (0x969f9e);
		else if (alt <= 18)
			return (0xc9e7df);
		else
			return (0xFFFFFF);
	}
	if (alt < 0)
		return (0x0000FF);
	return (0x00FF00);
}
