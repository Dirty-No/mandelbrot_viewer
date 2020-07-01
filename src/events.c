/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:56:42 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 01:03:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "mandelbrot.h"

int			press_handler(int keycode, t_game *game)
{
	if (keycode == FORWARD_KEY)
		game->keys |= FORWARD_PRESSED;
	else if (keycode == BACKWARD_KEY)
		game->keys |= BACKWARD_PRESSED;
	else if (keycode == RIGHT_KEY)
		game->keys |= RIGHT_PRESSED;
	else if (keycode == LEFT_KEY)
		game->keys |= LEFT_PRESSED;
	return (0);
}

int			release_handler(int keycode, t_game *game)
{
	if (keycode == FORWARD_KEY)
		game->keys &= FORWARD_RELEASED_MASK;
	else if (keycode == BACKWARD_KEY)
		game->keys &= BACKWARD_RELEASED_MASK;
	else if (keycode == RIGHT_KEY)
		game->keys &= RIGHT_RELEASED_MASK;
	else if (keycode == LEFT_KEY)
		game->keys &= LEFT_RELEASED_MASK;
	return (0);
}

int			key_handler(long keys, t_game *game)
{
	if (keys & FORWARD_PRESSED_MASK)
	{
		game->cursor_y -= CURSOR_SPEED;
		game->plane->y_min += PLANE_SPEED / game->zoom_level;
		game->plane->y_max += PLANE_SPEED / game->zoom_level;
	}
	if (keys & BACKWARD_PRESSED_MASK)
	{
		game->cursor_y += CURSOR_SPEED;
		game->plane->y_min -= PLANE_SPEED / game->zoom_level;
		game->plane->y_max -= PLANE_SPEED / game->zoom_level;
	}
	if (keys & RIGHT_PRESSED_MASK)
	{
		game->cursor_x += CURSOR_SPEED;
		game->plane->x_min += PLANE_SPEED / game->zoom_level;
		game->plane->x_max += PLANE_SPEED / game->zoom_level;
	}
	if (keys & LEFT_PRESSED_MASK)
	{
		game->cursor_x -= CURSOR_SPEED;
		game->plane->x_min -= PLANE_SPEED / game->zoom_level;
		game->plane->x_max -= PLANE_SPEED / game->zoom_level;
	}
	return (0);
}

void		hooks(t_window *win, t_game *game)
{
	mlx_loop_hook(win->mlx, loop_handler, game);
	mlx_hook(win->win, KEY_PRESS, KEYPRESS_MASK, press_handler, game);
	mlx_hook(win->win, KEY_RELEASE, KEYRELEASE_MASK, release_handler, game);
}