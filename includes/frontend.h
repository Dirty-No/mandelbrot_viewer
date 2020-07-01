/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontend.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:50:05 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 01:15:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRONTEND_H
# define FRONTEND_H
# include "structs.h"
# include "libc.h"

int     create_rgb(unsigned char r, unsigned char g, unsigned char b) 
        __attribute__((hot)) __attribute__((pure));

void     my_mlx_pixel_put(t_data *data, int x, int y, int color) 
        __attribute__((hot));

void    drawRectangle(t_data *data, int top_left[2], int bot_right[2]);
void	draw_cross(t_data *img, int x, int y, int size);

#endif