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
# include <stdlib.h>

# define ABS(Value) ((Value) < 0 ? -(Value) : (Value))

# define ESC 53
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define PAGE_UP 116
# define PAGE_DOWN 121

typedef struct			s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}						t_img;

typedef struct			s_coord
{
	int						x;
	int						y;
	int						z;
	float					prt_x;
	float					prt_y;
	struct s_coord			*next;
	struct s_coord			*prev;
}						t_coord;

typedef struct			s_params
{
	t_coord				*coords;
	t_img				img;
	int					max_hori_win;
	int					max_vert_win;
	int					lag_x;
	int					lag_y;
	int					zoom;
	int					last_key;
	float				speed;
	void				*mlx_ptr;
	void				*win_ptr;
}						t_params;

t_params				*fill_params(t_coord *coords);

void					ft_free_lst(t_coord *coords);

void					init_drawing(t_params *param);

void		line_and_diag(t_params *param, t_coord *coords, t_coord *coord_nxt);

void		line_vert(t_params *param, t_coord *coords, t_coord *coord_nxt);

t_coord		*finded_down(t_coord *coord, int x, int y);

t_coord		*finded_diag(t_coord *coord, int x, int y);

void		ft_put_pixel(t_coord *coord, void *mlx_ptr, void *win_ptr);

int			key_holder(int key, t_params *param);

void		prt_form(t_params *param);

void	bresenham_finder(int x0,int y0,int x1,int y1, t_params *param);

#endif
