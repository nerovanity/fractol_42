/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:46:37 by ihamani           #+#    #+#             */
/*   Updated: 2025/02/23 08:34:19 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define WIDTH 800
# define HEIGHT 800

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	double	zoom;
	double	x;
	double	y;
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	shift_x;
	double	shift_y;
	int		r;
	int		g;
	int		b;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		set;
	char	*title;
	char	*addr;
}	t_data;

double	ft_atod(char *str);
int		args(int ac, char **av);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *str, int fd);
int		ft_strcmp(char *s1, char *s2);
void	hooks_handle(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
double	scale(int pixel, double max, double min, int size);
void	close_mlx(t_data *data);
void	mandelbrot(t_data *data);
void	drawing_fractal_set(t_data *data, int option);
void	julia(t_data *data, double j_x, double j_y);
int		check_sign(char *str);
int		coloring(int i, int max, t_data data);
void	destroy(t_data *data);
void	burning_ship(t_data *data);
void	mlx_events(t_data *data);
void	throw_err(char *str);
double	calc(double pixel, double max, double min, t_data *data);

#endif