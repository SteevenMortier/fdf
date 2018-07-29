/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_m_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 11:31:27 by smortier          #+#    #+#             */
/*   Updated: 2018/03/03 11:31:29 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		where_m_i(int index, int end)
{
	ft_putstr("Step \e[42m[");
	ft_putnbr(index);
	ft_putstr("]\e[0m / ");
	ft_putnbr(end);
	ft_putstr(" \n");
}
