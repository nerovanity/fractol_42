/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:03:34 by ihamani           #+#    #+#             */
/*   Updated: 2025/02/19 14:12:30 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	hooks_handle(t_data *data)
{
	mlx_mouse_hook(data->win, mouse_wheel, data);
}

int	mouse_wheel(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom *= 0.9;
	else
		return (0);
	if (data->set == 1)
		drawing_fractal_set(data, 1);
	else if (data->set == 2)
		drawing_fractal_set(data, 2);
	else if (data->set == 3)
		drawing_fractal_set(data, 3);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

double	scale(int pixel, double max, double min, int size)
{
	return (min + (((max - min) * pixel) / size));
}

int	check_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if ((i > 0 && str[i - 1] != ' ') || !str[i + 1])
				return (0);
		}
		i++;
	}
	return (1);
}
