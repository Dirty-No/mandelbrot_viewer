/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:59:47 by user42            #+#    #+#             */
/*   Updated: 2020/07/01 01:17:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "structs.h"
# include "libc.h"

void		init_window(t_data *buf, t_window *window);
void		init_img(void *mlx, int width, int height, t_data *img);

#endif