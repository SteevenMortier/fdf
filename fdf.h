/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:23:07 by smortier          #+#    #+#             */
/*   Updated: 2018/01/24 23:23:10 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>

# define ABS(Value) ((Value) < 0 ? -(Value) : (Value))

typedef struct			s_params
{
	float					x;
	float					y;
	float					z;
	float					prt_x;
	float					prt_y;
	struct s_params		*next;
	struct s_params		*prev;
}						t_params;

void					ft_free_lst(t_params *param);

void					init_drawing(t_params *param);

#endif
