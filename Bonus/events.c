/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:12:00 by ihamani           #+#    #+#             */
/*   Updated: 2025/02/19 14:04:05 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	color_shift(t_data *data, int i)
{
	data->r += i;
	data->g += i;
	data->b += i;
}

int	key(int keycode, t_data *data)
{
	if (keycode == 65363)
		data->shift_x += 0.5 * data->zoom;
	else if (keycode == 65361)
		data->shift_x -= 0.5 * data->zoom;
	else if (keycode == 65364)
		data->shift_y += 0.5 * data->zoom;
	else if (keycode == 65362)
		data->shift_y -= 0.5 * data->zoom;
	else if (keycode == 61)
		color_shift(data, 1);
	else if (keycode == 45)
		color_shift(data, -1);
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


void	mlx_events(t_data *data)
{
	mlx_key_hook(data->win, key, data);
}
