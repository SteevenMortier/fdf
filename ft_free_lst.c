/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 04:37:41 by smortier          #+#    #+#             */
/*   Updated: 2018/01/25 04:37:49 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_free_lst(t_params *param)
{
	t_params		*temp;

	//fait gaffe a ce que la lst soit bien au dbut
	if (param)
	{
		while (param)
		{
			temp = param;
			param = param->next;
			ft_memdel((void **)&temp);
		}
	}
}