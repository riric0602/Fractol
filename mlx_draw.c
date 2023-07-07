/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:34:51 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/19 19:46:00 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	last_draw(t_data *data, int x, int y, int iter)
{
	if (iter == 250)
		my_mlx_pixel_put(data, x, y, 0x000000);
	else
	{
		(data->color).color = (data->color).color_modif + (iter * 255) / 50;
		my_mlx_pixel_put(data, x, y, (data->color).color * 0x010000 \
			+ (data->color).color * 0x000001 + (data->color).color);
	}
}

int	draw_utils(t_data *data, t_complex z)
{
	int			i;
	t_complex	c;
	long double	tmp;

	c = (data->c);
	i = 0;
	while ((i < 250) && ((z.real * z.real) + (z.imaginary * z.imaginary)) < 4)
	{
		tmp = z.real;
		z.real = (z.real * z.real) - (z.imaginary * z.imaginary) + c.real;
		z.imaginary = (2 * z.imaginary * tmp) + c.imaginary;
		i++;
	}
	return (i);
}

void	mlx_regenerate(t_data *data)
{		
	if (data->fractal == 1)
		mandelbrot_set(data);
	if (data->fractal == 2)
		julia_set(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	zoom_modifs(t_data *data, double prev_zoom, int x, int y)
{
	double	mouse_r;
	double	mouse_i;
	t_coord	*var;

	var = data->coord;
	mouse_r = (x / (double)WIDTH) * (var->x_max - var->x_min) + var->x_min;
	mouse_i = (y / (double)HEIGHT) * (var->y_max - var->y_min) + var->y_min;
	var->x_min = mouse_r - (mouse_r - var->x_min) * (data->g_zoom / prev_zoom);
	var->x_max = mouse_r + (var->x_max - mouse_r) * (data->g_zoom / prev_zoom);
	var->y_min = mouse_i - (mouse_i - var->y_min) * (data->g_zoom / prev_zoom);
	var->y_max = mouse_i + (var->y_max - mouse_i) * (data->g_zoom / prev_zoom);
	var->zoom_x = WIDTH / (var->x_max - var->x_min);
	var->zoom_y = HEIGHT / (var->y_max - var->y_min);
}
