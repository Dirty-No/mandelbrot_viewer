/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:53:31 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 01:17:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "init.h"

void			init_img(void *mlx, int width, int height, t_data *img)
{
	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img,
	&(img->bits_per_pixel), &(img->line_length),
								 &(img->endian));
	img->width = width;
	img->height = height;
}

void		init_window(t_data *buf, t_window *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->width, window->height, "mandelbrot");
	init_img(window->mlx, window->width, window->height, buf);
	init_img(window->mlx, window->width, window->height, buf + 1);
}
