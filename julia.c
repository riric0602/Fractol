/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:27:07 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/19 20:46:29 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_coord_julia(t_data *data)
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;

	(data->coord)->x_min = -1.5;
	(data->coord)->x_max = 1.5;
	(data->coord)->y_min = -1.5;
	(data->coord)->y_max = 1.5;
	x_min = (data->coord)->x_min;
	x_max = (data->coord)->x_max;
	y_min = (data->coord)->y_min;
	y_max = (data->coord)->y_max;
	(data->coord)->zoom_x = WIDTH / (x_max - x_min);
	(data->coord)->zoom_y = HEIGHT / (y_max - y_min);
}

void	julia_set(t_data *data)
{
	int			x;
	int			y;
	t_coord		*var;
	t_complex	z;
	t_complex	c;

	mlx_clear_window(data->mlx, data->win);
	x = 0;
	var = (data)->coord;
	c = data->c;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z.real = (x / var->zoom_x) + var->x_min + c.c_real_modif;
			z.imaginary = (y / var->zoom_y) + var->y_min + c.c_imaginary_modif;
			last_draw(data, x, y, draw_utils(data, z));
			y++;
		}
		x++;
	}
}
