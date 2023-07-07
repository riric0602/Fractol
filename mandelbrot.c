/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:08:23 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/19 19:24:18 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_coord_mandelbrot(t_data *data)
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;

	(data->coord)->x_min = -2.5;
	(data->coord)->x_max = 1.0;
	(data->coord)->y_min = -1.2;
	(data->coord)->y_max = 1.2;
	x_min = (data->coord)->x_min;
	x_max = (data->coord)->x_max;
	y_min = (data->coord)->y_min;
	y_max = (data->coord)->y_max;
	(data->coord)->zoom_x = WIDTH / (x_max - x_min);
	(data->coord)->zoom_y = HEIGHT / (y_max - y_min);
}

void	mandelbrot_set(t_data *data)
{
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;
	t_coord		*var;

	x = 0;
	var = data->coord;
	c = (data->c);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z.real = 0;
			z.imaginary = 0;
			last_draw(data, x, y, draw_utils(data, z));
			y++;
			c.real = (x / var->zoom_x) + var->x_min + c.c_real_modif;
			c.imaginary = (y / var->zoom_y) + var->y_min + c.c_imaginary_modif;
			data->c = c;
		}
		x++;
	}
}
