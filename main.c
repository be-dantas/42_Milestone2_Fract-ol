/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:18:14 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/10/13 10:53:12 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void color_func(t_access *acs, int x, int y, int color)
{
	char	*pixel;
	
	pixel = acs->img_pointer + (y * acs->line_len + x * (acs->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}


int o_complex_faz_parte_do_fractal(double re, double im, int max_iter)
{
    double  a = 0.0;
    double  b = 0.0;
    int     i = 0;
    double  temp;

    while (i < max_iter && (a * a + b * b <= 4.0))
    {
        temp = a * a - b * b + re;
        b = 2 * a * b + im;
        a = temp;
        i++;
    }
    if (i == max_iter)
        return (1);
    else
		return (0);
}


// flag = 0 (X para RE), flag = 1.. (Y para IM)
double transformar_re_im(t_zoom *z , int x, int y, int flag)
{
	if (flag == 0)
		return (((double)x / WIDTH) * (4.0 / z->zoom)) - (2.0 / z->zoom) + z->coordenada_x;
		// return ((double)x / (WIDTH - 1)) * 5.0 - 2.0;
	else if (flag == 1)
		return (-((double)y / WIDTH) * (4.0 / z->zoom)) - (2.0 / z->zoom) + z->coordenada_x;
		// return -((double)y / (HEIGHT - 1)) * 5.0 + 2.0;
}


void	put_image(t_access *acs, t_zoom *z)
{
	int			x;
	int			y;
	t_complex	cmpx;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cmpx.re = transformar_re_im(z, x, y, 0);
			cmpx.im = transformar_re_im(z, x, y, 1);
			if (o_complex_faz_parte_do_fractal(cmpx.re, cmpx.im, z->max_iter) == 1)
				color_func(acs, x, y, 0x000000);
			else
				color_func(acs, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(acs->mlx_connection, acs->mlx_window, acs->img, 0, 0);
}


int	main(void)
{
	t_access	acs;
	t_zoom		z;

	acs.mlx_connection = mlx_init();
	acs.mlx_window = mlx_new_window(acs.mlx_connection, WIDTH, HEIGHT, "Fract-ol");
	
	acs.img = mlx_new_image(acs.mlx_connection, WIDTH, HEIGHT);
	acs.img_pointer = mlx_get_data_addr(acs.img, &acs.bits_per_pixel, &acs.line_len, &acs.endian);

    z.zoom = 1.0;
    z.coordenada_x = 0.0;
    z.coordenada_y = 0.0;
    z.max_iter = 42;


	put_image(&acs, &z);


	mlx_loop(acs.mlx_connection);
	return (0);
}
