/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:18:14 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/10/14 14:21:34 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_func_mandelbroot(t_access *acs, int x, int y)
{
	char	*pixel;
	int		i;
	int		t;
	int		color;

	color = 0;
	pixel = acs->img_pointer + (y * acs->line_len + x * (acs->bits_px / 8));
	i = if_mandelbroot(acs->re, acs->im, acs->max_iter);
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

int	if_mandelbroot(double re, double im, int max_iter)
{
	double	a;
	double	b;
	double	a2;
	double	b2;
	int		i;

	a = 0.0;
	b = 0.0;
	a2 = 0.0;
	b2 = 0.0;
	i = 0;
	if ((re + 1) * (re + 1) + im * im > 16.0)
		return (0);
	while (i < max_iter)
	{
		a2 = a * a;
		b2 = b * b;
		if (a2 + b2 > 4.0)
			return (i);
		b = 2 * a * b + im;
		a = a2 - b2 + re;
		i++;
	}
	return (-1);
}
