#include "fdf.h"

void	ft_draw_image(t_params *param)
{
	int		x_img;
	int 	y_img;

	y_img = -1;
	param->img.img_ptr = mlx_new_image(param->mlx_ptr, WIDTH,
									   HIGHT);
	param->img.data = (int *)mlx_get_data_addr(param->img.img_ptr, &param->img.bpp, &param->img.size_l,
											&param->img.endian);
	while (++y_img < HIGHT)
	{
		x_img = -1;
		while (++x_img < WIDTH)
		{
			if (param->bres_tab[x_img][y_img])
				param->img.data[y_img * WIDTH + x_img] = param->bres_tab[x_img][y_img];
			else
				param->img.data[y_img * WIDTH + x_img] = 0;
		}
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img.img_ptr, 0, 0);
}
