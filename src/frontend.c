/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:44:29 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 00:55:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frontend.h"

int	__attribute__((hot)) __attribute__((pure)) 
    create_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

void	__attribute__((hot)) my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		draw_cross(t_data *img, int x, int y, int size)
{
	int x0 = x - size / 2 - 1;
	int y0 = y - size / 2 - 1;

	while (++x0 < x + size / 2)
		my_mlx_pixel_put(img, x0, y, 0xFFFFFF);
	while (++y0 < y + size / 2)
		my_mlx_pixel_put(img, x, y0, 0xFFFFFF);
}


void    	drawRectangle(t_data *data, int top_left[2], int bot_right[2])
{
        int i;

        i = top_left[0];
        while (i <= bot_right[0])
        {
                my_mlx_pixel_put(data, i, top_left[1], 0x00FFFFFF);
                my_mlx_pixel_put(data, i, bot_right[1], 0x00FFFFFF);
                i++;
        }
        i = top_left[1];
        while (i <= bot_right[1])
        {
                my_mlx_pixel_put(data, top_left[0], i, 0x00FFFFFF);
                my_mlx_pixel_put(data, bot_right[0], i, 0x00FFFFFF);
                i++;
        }
}
