/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:46:37 by ihamani           #+#    #+#             */
/*   Updated: 2025/02/19 12:54:42 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH	800
# define HEIGHT	800

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	double	zoom;
	double	x;
	double	y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		set;
	char	*title;
	char	*addr;
}				t_data;

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
int		mouse_wheel(int button, int x, int y, t_data *data);
void	julia(t_data *data, double j_x, double j_y);
int		check_sign(char *str);
int		coloring(int i, int max);
void	destroy(t_data *data);

#endif