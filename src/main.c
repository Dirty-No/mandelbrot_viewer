/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 20:02:05 by smaccary          #+#    #+#             */
/*   Updated: 2020/07/01 01:35:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbrot.h"

void __attribute__((hot)) draw_mandelbrot(t_window *win, t_data *buf, t_plane *plane, size_t max_iter)
{
	int		y =	-1;
	int		x;
	t_point	c = (t_point){0};
	t_point	n = (t_point){0};
	t_point tmp = (t_point){0};

	while (++y < win->height)
	{
		x = -1;
		while (++x < win->width)
		{
			c.x = (x * (plane->x_max - plane->x_min) / win->width + plane->x_min);
			c.y = (y * (plane->y_min - plane->y_max) / win->height + plane->y_max);
			n = (t_point){0};
			while ((n.x * n.x + n.y * n.y) < 4 && n.val < max_iter)
			{
				tmp = (t_point){n.x, n.y, 0};
				n = (t_point){tmp.x * tmp.x - tmp.y * tmp.y + c.x, 2 * tmp.x * tmp.y + c.y, n.val + 1};
			}
			if (n.val == max_iter)
				my_mlx_pixel_put(buf, x, y, 0x0);
			else
				my_mlx_pixel_put(buf, x, y,
				create_rgb((3 * n.val), (1 * n.val), (10 * n.val)));
		}
	}
}

void		zoom_plane(t_game *game, double zoom)
{
	t_plane			*plane = (game->plane);
	static size_t	count = 0;

	plane->x_min=plane->x_min + (zoom / game->zoom_level); 
	plane->x_max=plane->x_max - (zoom / game->zoom_level); 
	plane->y_min=plane->y_min + (zoom / game->zoom_level); 
	plane->y_max=plane->y_max - (zoom / game->zoom_level);
	
	game->redraw = 1;
	game->cursor_x = WIN_WIDTH / 2;
	game ->cursor_y  = WIN_HEIGHT / 2;
	game->zoom_level = 1 / (plane->x_max - plane->x_min);
	if (++count > ITER_STEP)
	{
		game->max_iter++;
		count = 0;
	}
}

int			loop_handler(t_game *game)
{
	static clock_t	t0 = 0;
	static int		i = 0;
	static int		frame_ready = 0;

	t_window		*window = (game->win);
	t_data			*buffers = game->buffs;

	
	if (!frame_ready)
	{
		draw_mandelbrot(window, buffers + i, game->plane, game->max_iter);
		draw_cross(buffers + i, game->cursor_x, game->cursor_y, 10);
		frame_ready = 1;
	}
	if (clock() - t0 >= CLOCKS_PER_SEC / FRAMECAP)
	{
		t0 = clock();
		key_handler(game->keys, game);
		zoom_plane(game, ZOOM );
	}
	if (game->redraw)
	{
		mlx_put_image_to_window(window->mlx, window->win, buffers[i].img, 0, 0);
		frame_ready = 0;
		i = (i) ? 0 : 1;
		game->redraw = 0;
	}
	return (0);
}

int			main(void)
{
	t_data		buffers[2];
	t_plane		plane = (t_plane){MIN_X0, MAX_X0, MIN_Y0, MAX_Y0};
	t_window	window = (t_window){WIN_WIDTH, WIN_HEIGHT, 0, 0};
	t_game		game = (t_game){buffers, &window, &plane, WIN_WIDTH / 2, WIN_HEIGHT / 2, 0, 0, 1.0, MIN_ITER};
	
	init_window(buffers, &window);
	hooks(&window, &game);
	mlx_loop(window.mlx);
	return (0);
}