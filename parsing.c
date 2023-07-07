/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:53:04 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/19 20:40:20 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	double_conversion(char *str, int end, int i)
{
	int			size;
	long double	res;
	long double	first;
	char		*second;

	first = (long double)ft_atoi(ft_substr(str, i, end - i));
	second = ft_substr(str, end + 1, ft_strlen(str) - end - i);
	size = ft_strlen(second);
	res = (long double)ft_atoi(second);
	i = 0;
	while (i++ < size)
		res = res / 10;
	res += first;
	return (res);
}

double	julia_element(char *str)
{
	int			i;
	int			end;
	long double	res;
	int			minus;

	i = 0;
	minus = 1;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	end = i;
	while (str[end] != '.')
		end++;
	res = double_conversion(str, end, i);
	return (res * minus);
}

void	ft_error_param(t_data *data)
{
	free(data->coord);
	free(data);
	exit(EXIT_FAILURE);
}

void	ft_print_param(t_data *data, int index)
{
	if (index == 1)
	{	
		ft_printf(RED "---Enter Valid Arguments for Julia :---");
		ft_printf(BLUE "\n\t0.3\t\t0.5\n\t0.285\t\t0.01 \
			\n\t-1.417022285618 0.0099534\n");
		ft_printf("\t-0.038088\t0.9754633\n\t0.285\t\t0.013\n");
		ft_printf("\t-1.476\t\t0\n\t-0.4\t\t0.6\n\t-0.8\t\t0.156\n" EOC);
	}
	else if (index == 2)
	{
		ft_printf(CYAN "     Enter Mandelbrot or Julia to visualize the project.\
			\n" EOC);
	}
	ft_error_param(data);
}

void	switch_fractal(char **argv, int argc, t_data *data)
{
	(data->c).c_real_modif = 0.0;
	(data->c).c_imaginary_modif = 0.0;
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 \
		|| ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractal = 1;
		init_coord_mandelbrot(data);
		data->c.real = 0;
		data->c.imaginary = 0;
		mandelbrot_set(data);
	}
	else if (ft_strcmp(argv[1], "Julia") == 0 \
		|| ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
			ft_print_param(data, 1);
		(data->c).real = julia_element(argv[2]);
		(data->c).imaginary = julia_element(argv[3]);
		data->fractal = 2;
		init_coord_julia(data);
		julia_set(data);
	}
	else
		ft_print_param(data, 2);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
