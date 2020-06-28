/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 20:02:44 by smaccary          #+#    #+#             */
/*   Updated: 2020/06/28 19:59:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
# include <mlx.h>
# include <time.h>
# include <stdio.h>
# include "events.h"

# define ABS(x) ((x < 0) ? (x) * -1 : x)
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_ITER 50
# define ZOOM 0.995
# define FRAMECAP 120
# define CURSOR_SPEED 5

# define FORWARD_PRESSED 1L
# define BACKWARD_PRESSED (1L << 1)
# define RIGHT_PRESSED (1L << 2)
# define LEFT_PRESSED (1L << 3)

# define FORWARD_PRESSED_MASK 0b0001
# define BACKWARD_PRESSED_MASK 0b0010
# define RIGHT_PRESSED_MASK 0b0100
# define LEFT_PRESSED_MASK 0b1000

# define FORWARD_RELEASED_MASK 0b1110
# define BACKWARD_RELEASED_MASK 0b1101
# define RIGHT_RELEASED_MASK 0b1011
# define LEFT_RELEASED_MASK 0b0111

int mlx_mouse_get_pos(void *mlx_ptr, int *x, int *y);


typedef struct s_point
{
	long double	x;
	long double y;
	int val;
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

typedef struct	s_game
{
	t_data		*buffs;
	t_window	*win;
	t_plane		*plane;
	int			cursor_x;
	int			cursor_y;
	int			redraw;
	long			keys;
}				t_game;


#endif