/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:30:48 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/16 11:08:38 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_access *access)
{
	if (access->img)
		mlx_destroy_image(access->connec, access->img);
	if (access->window)
		mlx_destroy_window(access->connec, access->window);
	if (access->connec)
	{
		mlx_destroy_display(access->connec);
		free(access->connec);
	}
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_access	*acs;
	double		move_speed;

	acs = (t_access *)param;
	move_speed = 0.1 / acs->zoom;
	if (keycode == 65307)
		close_window(acs);
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
