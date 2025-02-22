/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nero <nero@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:31:43 by ihamani           #+#    #+#             */
/*   Updated: 2025/02/22 18:23:28 by nero             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	skip_ws(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

double	decimal(char *str, double r, int i)
{
	double	t;
	int		j;

	t = 10;
	j = i + 1;
	if (i == 0 || !str[j] || str[j] == '.')
		throw_err("please provide a valid number\n");
	if (i != 0 && !(str[i - 1] >= '0' && str[j - 1] <= '9'))
		throw_err("please provide a valid number\n");
	while (str[j] && str[j] >= '0' && str[j] <= '9')
	{
		r += (str[j] - '0') / t;
		t *= 10;
		j++;
	}
	if (str[j])
		throw_err("please provide a valid number\n");
	return (r);
}

double	ft_atod(char *str)
{
	double	r;
	int		i;
	double	sign;

	r = 0;
	i = 0;
	sign = 1;
	i = skip_ws(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = (r * 10) + (str[i++] - '0');
	if (str[i] && str[i] == '.')
		r = decimal(str, r, i);
	if ((r * sign) > 2 || (r * sign) < -2)
		throw_err("a number between 2.0 and -2.0\n");
	return (r * sign);
}

int	coloring(int i, int max)
{
	int	r;
	int	g;
	int	b;

	if (i == max)
		return (0x000000);
	r = (i * 5 + 50) % 256;
	g = (i * 3 + 100) % 256;
	b = (i * 7 + 150) % 256;
	return (r << 16 | g << 8 | b);
}

int	args(int ac, char **av)
{
	if (ac == 2 && !ft_strcmp(av[1], "Mandelbrot"))
		return (1);
	else if (ac == 4 && !ft_strcmp(av[1], "Julia"))
		return (2);
	else
	{
		if (ac == 2 && !ft_strcmp(av[1], "Julia"))
			ft_putstr_fd("./fractol Julia \"-0.8\" \"0.156\"\n", 2);
		else
			ft_putstr_fd("./fractol \"Mandelbrot or Julia\"\n", 2);
		return (-1);
	}
	return (0);
}
