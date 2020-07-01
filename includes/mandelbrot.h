/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 20:02:44 by smaccary          #+#    #+#             */
/*   Updated: 2020/07/01 02:04:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H

# include "events.h"
# include "frontend.h"
# include "init.h"
# include "structs.h"
# include "libc.h"

# define ABS(x) ((x < 0) ? (x) * -1 : x)
# define WIN_WIDTH 400
# define WIN_HEIGHT 400

# define MIN_ITER 50
# define ITER_STEP 15

# define ZOOM 0.005
# define FRAMECAP 60
# define CURSOR_SPEED 2
# define PLANE_SPEED 0.01

# define MIN_X0 -2
# define MAX_X0 0.5
# define MIN_Y0 -1.25
# define MAX_Y0 1.25

#endif
