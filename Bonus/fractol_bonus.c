/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:51:24 by ihamani           #+#    #+#             */
/*   Updated: 2025/02/19 13:45:52 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	drawing_fractal_set(t_data *data, int set)
{
	if (set == 1)
		mandelbrot(data);
	else if (set == 2)
		julia(data, data->x, data->y);
	else if (set == 3)
		burning_ship(data);
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
	data.shift_x = 0;
	data.shift_y = 0;
	data.r = 25;
	data.g = 18;
	data.b = 8;
	drawing_fractal_set(&data, data.set);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	hooks_handle(&data);
	mlx_events(&data);
	close_mlx(&data);
	mlx_loop(data.mlx);
	return (0);
}

void	check_double(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
	{
		ft_putstr_fd("./fractol Julia \"0.8\" \"0.2\"", 2);
		exit(1);
	}
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| str[i] == '.' || str[i] == '-' || str[i] == '+'))
		{
			ft_putstr_fd("./fractol Julia \"0.8\" \"0.2\"", 2);
			exit(1);
		}
		i++;
	}
	if (check_sign(str) == 0)
	{
		ft_putstr_fd("./fractol Julia \"0.8\" \"0.2\"", 2);
		exit(1);
	}
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
	{
		ft_putstr_fd("somthing went wrong\n", 2);
		exit(1);
	}
	return (0);
}
