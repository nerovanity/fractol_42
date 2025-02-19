/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:46:41 by ihamani           #+#    #+#             */
/*   Updated: 2025/02/19 14:27:44 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterating_man(double real, double imag)
{
	int		i;
	double	new_real;
	double	new_imag;
	double	tmp;

	new_real = real;
	new_imag = imag;
	i = 0;
	while (((new_real * new_real) + (new_imag * new_imag) < 4) && i < 100)
	{
		tmp = (new_real * new_real) - (new_imag * new_imag) + real;
		new_imag = 2 * new_real * new_imag + imag;
		new_real = tmp;
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *data)
{
	int		x;
	int		y;
	int		color;
	double	real;
	double	imag;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = scale(x, 1.0, -2.0, WIDTH) * data->zoom;
			imag = scale(y, 1.5, -1.5, HEIGHT) * data->zoom;
			color = coloring(iterating_man(real, imag), 100);
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}
