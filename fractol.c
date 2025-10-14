/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:18:14 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/10/14 14:22:06 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_access	acs;

	acs.connec = mlx_init();
	acs.window = mlx_new_window(acs.connec, WIDTH, HEIGHT, "Fract-ol");
	acs.img = mlx_new_image(acs.connec, WIDTH, HEIGHT);
	acs.img_pointer = mlx_get_data_addr(acs.img, &acs.bits_px,
			&acs.line_len, &acs.endian);
	acs.zoom = 1.0;
	acs.max_iter = 200;
	acs.pos_x = 0.0;
	acs.pos_y = 0.0;
	put_image(&acs);
	mlx_mouse_hook(acs.window, mouse_hook, &acs);
	mlx_key_hook(acs.window, key_hook, &acs);
	mlx_loop(acs.connec);
	return (0);
}
