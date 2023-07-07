/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:07:28 by rchbouki          #+#    #+#             */
/*   Updated: 2023/05/23 22:47:20 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isprint(int c)
{
	if ((c == 26) || (c < 32) || (c > 126))
		return (0);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	char	l;
	char	*sub_set;

	sub_set = (char *)(s);
	l = (char)(c);
	while (*sub_set)
	{
		if (*sub_set == l)
			return (sub_set);
		sub_set++;
	}
	if (l == '\0')
		return (sub_set);
	return (NULL);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
