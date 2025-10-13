/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:21:25 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/10/13 18:49:08 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_access
{
	double	re;
	double	im;

	void	*connec;
	void	*window;
	void	*img;
	char	*img_pointer;
	int		bits_px;
	int		line_len;
	int		endian;

	double	zoom;
	int		max_iter;
	double	pos_x;
	double	pos_y;

	double	old_re;
	double	old_im;
	double	new_re;
	double	new_im;
}	t_access;

//mandelbroot
void	color_func(t_access *acs, int x, int y);
int		if_mandelbroot(double re, double im, int max_iter);
double	re_im(t_access *acs, int x, int y, int flag);
int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);
void	put_image(t_access *acs);

#endif
