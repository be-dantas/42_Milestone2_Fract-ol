/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:18:14 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/10/13 19:00:14 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	valid_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		write (1, "Inputs valids:\n", 13);
		write (1, "./fractol mandelbroot\n", 22);
		write (1, "./fractol julia 000 000\n", 24);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "mandelbroot", 11) == 0 && argc == 2)
		return (1);
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4)
		return (2);
	else
	{
		write (1, "Inputs valids:\n", 13);
		write (1, "./fractol mandelbroot\n", 22);
		write (1, "./fractol julia 000 000\n", 24);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_access	acs;

	acs.connec = mlx_init();
	acs.window = mlx_new_window(acs.connec, WIDTH, HEIGHT, "Fract-ol");
	acs.img = mlx_new_image(acs.connec, WIDTH, HEIGHT);
	acs.img_pointer = mlx_get_data_addr(acs.img, &acs.bits_px,
			&acs.line_len, &acs.endian);
	acs.zoom = 1.0;
	acs.max_iter = 50;
	acs.pos_x = 0.0;
	acs.pos_y = 0.0;
	put_image(&acs);
	mlx_mouse_hook(acs.window, mouse_hook, &acs);
	mlx_key_hook(acs.window, key_hook, &acs);
	mlx_loop(acs.connec);
	return (0);
}
