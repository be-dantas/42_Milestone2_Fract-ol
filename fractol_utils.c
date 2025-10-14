/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:09:45 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/14 18:48:54 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	re_im(t_access *acs, int x, int y, int flag)
{
	if (flag == 0)
		return (((double)x / WIDTH) * (4.0 / acs->zoom)
			- (2.0 / acs->zoom) + acs->pos_x);
	else if (flag == 1)
		return (-((double)y / HEIGHT) * (4.0 / acs->zoom)
			+ (2.0 / acs->zoom) + acs->pos_y);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_access	*acs;
	double		move_speed;

	acs = (t_access *)param;
	move_speed = 0.1 / acs->zoom;
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65361)
		acs->pos_x -= move_speed;
	else if (keycode == 65363)
		acs->pos_x += move_speed;
	else if (keycode == 65362)
		acs->pos_y += move_speed;
	else if (keycode == 65364)
		acs->pos_y -= move_speed;
	else
		return (0);
	mlx_destroy_image(acs->connec, acs->img);
	acs->img = mlx_new_image(acs->connec, WIDTH, HEIGHT);
	acs->img_pointer = mlx_get_data_addr(acs->img, &acs->bits_px,
			&acs->line_len, &acs->endian);
	put_image(acs);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_access	*access;

	access = (t_access *)param;
	access->old_re = re_im(access, x, y, 0);
	access->old_im = re_im(access, x, y, 1);
	if (button == 4)
	{
		access->zoom *= 1.05;
		access->max_iter *= 1.001;
	}
	else if (button == 5)
	{
		access->zoom /= 1.05;
		access->max_iter *= 1.001;
	}
	access->new_re = re_im(access, x, y, 0);
	access->new_im = re_im(access, x, y, 1);
	access->pos_x += (access->old_re - access->new_re);
	access->pos_y += (access->old_im - access->new_im);
	mlx_destroy_image(access->connec, access->img);
	access->img = mlx_new_image(access->connec, WIDTH, HEIGHT);
	access->img_pointer = mlx_get_data_addr(access->img, &access->bits_px,
			&access->line_len, &access->endian);
	put_image(access);
	return (0);
}

void	color_func(t_access *acs, int x, int y)
{
	char	*pixel;
	int		i;
	int		t;
	int		color;

	color = 0;
	pixel = acs->img_pointer + (y * acs->line_len + x * (acs->bits_px / 8));
	if (acs->fract == 1)
		i = if_mandelbroot(acs);
	else if (acs->fract == 2)
		i = if_julia(acs);
	if (i == -1)
		color = 0x000000;
	else
	{
		t = (int)(256.0 * sqrt((double)i / acs->max_iter));
		if (t > 255)
			t = 255;
		color = (t << 16) | (t << 8) | t;
	}
	*(unsigned int *)pixel = color;
}

void	put_image(t_access *acs)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		acs->im = re_im(acs, 0, y, 1);
		while (x < WIDTH)
		{
			acs->re = re_im(acs, x, y, 0);
			color_func(acs, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(acs->connec, acs->window, acs->img, 0, 0);
}
