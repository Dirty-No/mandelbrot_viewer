/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 20:02:44 by smaccary          #+#    #+#             */
/*   Updated: 2020/06/27 20:42:52 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
# include <mlx.h>
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_ITER 50
typedef struct s_point
{
	long double	x;
	long double y;
	long double val;
}				t_point;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_data;

typedef struct	s_plane
{
	long double	x_min;
	long double	y_min;
	long double	x_max;
	long double y_max;
}				t_plane;

typedef struct	s_window
{
	int			height;
	int			width;
	void		*mlx;
	void		*win;
}				t_window;

#endif