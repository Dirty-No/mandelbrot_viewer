/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 20:02:05 by smaccary          #+#    #+#             */
/*   Updated: 2020/06/27 20:48:43 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

int		create_rgb(unsigned char r, unsigned char g,
					unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	if (x <= 0 || x >= data->width || y <= 0 || y >= data->height)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		init_img(void *mlx, int width, int height, t_data *img)
{
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img,
	&(img->bits_per_pixel), &(img->line_length),
								 &(img->endian));
	img->width = width;
	img->height = height;
}

void	init_window(t_data *buf, t_plane *plane, t_window *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->width, window->height, "mandelbrot");
	init_img(window->mlx, window->width, window->height, buf);
	init_img(window->mlx, window->width, window->height, buf + 1);
}

void	draw_mandelbrot(t_window *win, t_data *buf, t_plane *plane)
{
	int		y =	-1;
	int		x =	-1;
	t_point	c = (t_point){0};
	t_point	n = (t_point){0};
	t_point tmp = (t_point){0};

	while (++y < win->height)
	{
		while (++x < win->width)
		{
			c.x = (x * (plane->x_max - plane->x_max) / win->width + plane->x_max);
			c.y = (y * (plane->y_min - plane->y_max) / win->height + plane->y_max);
			n = (t_point){0};
			while ((n.x * n.x + n.y * n.y) < 4 && n.val < MAX_ITER)
			{
				tmp = (t_point){n.x, n.y, 0};
				n = (t_point){tmp.x * tmp.x - tmp.y * tmp.y + c.x, 2 * tmp.x * tmp.y + c.y, n.val + 1};
			}
			if (n.val == MAX_ITER)
				my_mlx_pixel_put(buf, x, y, 0x0000FF);
			else
				my_mlx_pixel_put(buf, x, y, 0xFFFFFF);
			
		}
		
	}
	
}

int		main(void)
{
	t_data		buffers[2] = {(t_data){0}, (t_data){0}};
	t_plane		plane = (t_plane){-2, -1.25, 0.5, 1.25};
	t_window	window = (t_window){800, 800, 0, 0};
	
	init_window(buffers, &plane, &window);
	draw_mandelbrot(&window, buffers, &plane);
	mlx_put_image_to_window(window.mlx, window.win, buffers[0].img, 0, 0);
	for (int i = 0; i < window.width; i++)
		my_mlx_pixel_put(buffers, i, 200, 0xFFFFFF);
	mlx_loop(window.mlx);
	return (0);
}