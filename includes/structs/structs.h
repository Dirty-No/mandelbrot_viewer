/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:46:11 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 01:12:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>

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

typedef struct s_point
{
	long double	x;
	long double y;
	size_t		val;
}				t_point;

typedef struct	s_plane
{
	long double	x_min;
	long double	x_max;
	long double	y_min;
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
	long		keys;
	long double	zoom_level;
	size_t		max_iter;
}				t_game;

#endif
