/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nero <nero@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:21:41 by ihamani           #+#    #+#             */
/*   Updated: 2025/02/18 20:47:11 by nero             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy(t_data *data)
{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
}

int	esc(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		destroy(data);
		exit(0);
	}
	return (0);
}

int	close_b(t_data *data)
{
	destroy(data);
	exit(0);
	return (0);
}
void	close_mlx(t_data *data)
{
	mlx_hook(data->win, 2, 1, esc, data);
	mlx_hook(data->win, 17, 0, close_b, data);
}


