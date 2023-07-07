/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:23:29 by rchbouki          #+#    #+#             */
/*   Updated: 2023/06/19 20:44:05 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdarg.h>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define CYAN	"\033[1;35m"
# define BLUE	"\033[1;36m"
# define EOC	"\033[0;0m"

# define WIDTH			900
# define HEIGHT			700
# define ZOOM_DEFAULT	1.0

# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_UP	4
# define ESC				53
# define MOUSE_LEFT_CLICK	1
# define MOUSE_RIGHT_CLICK	2
# define UP					126
# define DOWN				125
# define LEFT				123
# define RIGHT				124

typedef struct s_complex
{
	long double	real;
	long double	imaginary;
	long double	c_real_modif;
	long double	c_imaginary_modif;
}	t_complex;

typedef struct s_coord
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	zoom_x;
	double	zoom_y;
}	t_coord;

typedef struct s_color
{
	int				color;
	int				color_modif;
}	t_color;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				endian;
	double			g_zoom;
	int				fractal;
	t_complex		c;
	t_color			color;
	t_coord			*coord;
	int				line_length;
	int				bits_per_pixel;
}	t_data;

void		switch_fractal(char **argv, int argc, t_data *img);
double		double_conversion(char *str, int end, int i);
double		julia_element(char *str);
void		ft_print_param(t_data *data, int index);

long int	ft_atoi(char *s);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_substr(char *s, int start, int len);

void		init_coord_mandelbrot(t_data *data);
void		mandelbrot_set(t_data *data);

void		init_coord_julia(t_data *data);
void		julia_set(t_data *data);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		last_draw(t_data *data, int x, int y, int iter);
int			draw_utils(t_data *data, t_complex z);
void		zoom_modifs(t_data *data, double prev_zoom, int x, int y);

void		ft_error_param(t_data *img);
void		mlx_close(t_data *data);
int			close_window(void *param);
void		mlx_regenerate(t_data *data);

int			esc_key(int keycode, t_data *data);
int			mouse_hook(int keycode, int x, int y, t_data *data);
int			key_hook(int keycode, t_data *data);

int			ft_isprint(int c);
void		ft_putchar(char c);
void		ft_putstr(char *s);
int			ft_write_s(va_list param);
int			ft_printf(const char *str, ...);
char		*ft_strchr(const char *s, int c);
int			ft_write_c(char c, va_list	param);
int			ft_write_d(va_list param, char *base, int test);

#endif