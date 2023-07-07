/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:40:23 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/20 18:12:50 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	long double	modif_index;

	if (data->g_zoom < 0.05)
		modif_index = 0.005;
	else
		modif_index = 0.06;
	if (keycode == UP)
		(data->c).c_imaginary_modif -= modif_index;
	else if (keycode == DOWN)
		(data->c).c_imaginary_modif += modif_index;
	else if (keycode == LEFT)
		(data->c).c_real_modif -= modif_index;
	else if (keycode == RIGHT)
		(data->c).c_real_modif += modif_index;
	mlx_regenerate(data);
	return (0);
}

int	esc_key(int keycode, t_data *data)
{
	if (keycode == ESC || keycode == 17)
		mlx_close(data);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	double	prev_zoom;
	double	zoom_factor;
	int		scroll_direction;

	zoom_factor = 1.15;
	scroll_direction = 0;
	prev_zoom = data->g_zoom;
	if (keycode == MOUSE_SCROLL_DOWN)
		scroll_direction = -1;
	else if (keycode == MOUSE_SCROLL_UP)
		scroll_direction = 1;
	else if (keycode == MOUSE_LEFT_CLICK)
		(data->color).color_modif += 200;
	else if (keycode == MOUSE_RIGHT_CLICK)
		(data->color).color_modif -= 200;
	data->g_zoom = data->g_zoom * pow(zoom_factor, scroll_direction);
	zoom_modifs(data, prev_zoom, x, y);
	mlx_regenerate(data);
	return (0);
}
