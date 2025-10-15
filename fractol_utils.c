/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:09:45 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/15 15:31:13 by bedantas         ###   ########.fr       */
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
	if (i == acs->max_iter)
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
