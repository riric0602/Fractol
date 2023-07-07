/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:05:32 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/20 18:08:44 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_initialazation(t_data *data)
{
	data->coord = malloc(sizeof(t_coord));
	if (!data->coord)
		ft_error_param(data);
	data->g_zoom = ZOOM_DEFAULT;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_error_param(data);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, \
		&data->bits_per_pixel, &data->line_length, &data->endian);
	(data->color).color_modif = 0;
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	data_initialazation(data);
	if (argc == 1)
		ft_print_param(data, 2);
	switch_fractal(argv, argc, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_hook(data->win, 2, 1L << 0, esc_key, data);
	mlx_hook(data->win, 3, 1L << 0, key_hook, data);
	mlx_hook(data->win, 4, 0, mouse_hook, data);
	mlx_loop(data->mlx);
	return (argc);
}
