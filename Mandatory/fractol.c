/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nero <nero@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:51:24 by ihamani           #+#    #+#             */
/*   Updated: 2025/02/22 18:21:44 by nero             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	drawing_fractal_set(t_data *data, int set)
{
	if (set == 1)
		mandelbrot(data);
	else if (set == 2)
		julia(data, data->x, data->y);
}

int	window_init(t_data data)
{
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, data.title);
	if (!data.win)
		return (mlx_destroy_display(data.mlx), free(data.mlx), 1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		return (mlx_destroy_window(data.mlx, data.win),
			mlx_destroy_display(data.mlx), free(data.mlx), 1);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	if (!data.addr)
		return (destroy(&data), 1);
	data.zoom = 1;
	drawing_fractal_set(&data, data.set);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	hooks_handle(&data);
	close_mlx(&data);
	mlx_loop(data.mlx);
	return (0);
}

void	throw_err(char *str)
{
	ft_putstr_fd(str ,2);
	exit(1);
}

void	check_double(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		throw_err("./fractol Julia \"-0.8\" \"0.156\"\n");
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'
				|| str[i] == '-' || str[i] == '+'))
			throw_err("./fractol Julia \"-0.8\" \"0.156\"\n");
		i++;
	}
	if (check_sign(str) == 0)
		throw_err("./fractol Julia \"-0.8\" \"0.156\"\n");
}

int	main(int ac, char **av)
{
	t_data	data;

	data.set = args(ac, av);
	if (data.set == -1)
		exit(1);
	else if (data.set == 2)
	{
		check_double(av[2]);
		data.x = ft_atod(av[2]);
		check_double(av[3]);
		data.y = ft_atod(av[3]);
	}
	data.title = av[1];
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	if (window_init(data))
		throw_err("somthing went wrong\n");
	return (0);
}
