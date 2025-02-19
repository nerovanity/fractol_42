/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:54:31 by ihamani           #+#    #+#             */
/*   Updated: 2025/02/19 14:26:41 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterating_julia(double real, double imag, double r, double im)
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
		tmp = (new_real * new_real) - (new_imag * new_imag) + r;
		new_imag = 2 * new_real * new_imag + im;
		new_real = tmp;
		i++;
	}
	return (i);
}

void	julia(t_data *data, double j_x, double j_y)
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
			real = scale(x, -2.0, 2.0, WIDTH) * data->zoom;
			imag = scale(y, 2.0, -2.0, HEIGHT) * data->zoom;
			color = coloring(iterating_julia(real, imag, j_x, j_y), 100);
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}
