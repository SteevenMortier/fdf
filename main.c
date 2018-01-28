/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 23:20:52 by smortier          #+#    #+#             */
/*   Updated: 2018/01/24 23:20:54 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_params	*ft_newparam(float x, float y, char *zstr)
{
	t_params		*newparam;

	if (!(newparam = (t_params *)ft_memalloc(sizeof(t_params))))
		return (NULL);
	newparam->x = (float)x;
	newparam->y = (float)y;
	newparam->z = (float)(ft_atoi(zstr)) ? ft_atoi(zstr) : 0;
	newparam->next = NULL;
	newparam->prev = NULL;
	ft_memdel((void **)&zstr);
	return (newparam);
}

t_params	*ft_create_lst(t_params *param, int x, int y, char *zstr)
{
	t_params	*temp;

	if (param == NULL)
		return (ft_newparam(x, y, zstr));
	else
	{
		temp = param;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_newparam(x, y, zstr);
		temp->next->prev = temp;
		return (param);
	}
}

t_params	*ft_fill_lst(t_params *param, char **map)
{
	float		y;
	float		x;
	int		index;
	int		save_pos;

	y = 0;
	while (map[(int)y])
	{
		index = 0;
		x = 0;
		while (map[(int)y][index])
		{
			save_pos = index;
			while (ft_isdigit(map[(int)y][save_pos]) || map[(int)y][save_pos] == '-')
				save_pos++;
			param = ft_create_lst(param, x, y, ft_strsub(map[(int)y], index,
														save_pos - index));
			x++;
			index = save_pos;
			while (map[(int)y][index] == ' ')
				index++;
		}
		y++;
	}
	return (param);
}

int			main(int ac, char **av)
{
	char		*line;
	char		*map[10000];
	t_params	*param;
	t_params	*temp;
	int			fd;
	int			i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		map[i] = line;
		i++;
	}
	map[i + 1] = NULL; //la map est rempli
	close(fd);
	param = ft_fill_lst(param, map);
	temp = param;
	i = 0; //y max
	fd = 0; //x max
	while (temp)
	{
		if (i <= temp->y)
			i = temp->y;
		if (fd <= temp->x)
			fd = temp->x;
		temp = temp->next;
	}
	init_drawing(param);
	///DEBUG PARAM /////////////////////
	while (param)
	{
		printf("%s%s%f\033[0m", (param->z >= 10 || param->z < 0) ? "\033[31m" : " ", (param->z < 10 && param->z) ? "\033[31m" : "",  param->z);
		if (param->next && param->y != param->next->y)
			printf("\n");
		param = param->next;
	}
	///FIN DEBUG PARAM ////////////////////
	//ft_free_lst(param); //0 leaks oklm
	//SWAAAAAAG => make re && ./fdf test_maps/42.fdf
	return (0);
}
