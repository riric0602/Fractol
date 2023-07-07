/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:34:33 by rchbouki          #+#    #+#             */
/*   Updated: 2023/05/23 22:41:42 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_fullstr(const char *str)
{
	int	len;

	len = ft_strlen((char *)str);
	write(1, str, len);
	return (len);
}

static int	ft_options(char c, va_list param)
{
	int	res;

	res = 0;
	if (c == 'c' || c == '%')
		res = ft_write_c(c, param);
	else if (c == 's')
		res = ft_write_s(param);
	else if (c == 'd' || c == 'i')
		res = ft_write_d(param, "0123456789", 0);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cp;
	va_list	param;

	i = 0;
	cp = 0;
	if (!ft_strchr(str, '%'))
		return (ft_fullstr(str));
	va_start(param, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			cp += ft_options(str[i + 1], param);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			cp++;
		}
		i++;
	}
	va_end(param);
	return (cp);
}
