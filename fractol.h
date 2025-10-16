/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:21:25 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/10/16 14:33:18 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_access
{
	double	re;
	double	im;
	double	j1;
	double	j2;
	int		fract;

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

//main.c
int		main(int argc, char **argv);

//fractol_utils.c
double	re_im(t_access *acs, int x, int y, int flag);
void	color_func(t_access *acs, int x, int y);
void	put_image(t_access *acs);

//valid_inputs.c
void	input_error(int flag);
int		valid_julia(char **av, t_access *acs);
int		valid_input(int ac, char **av, t_access *acs);

//mand_and_julia.c
int		if_mandelbrot(t_access *acs);
int		if_julia(t_access *acs);

//mouse_key.c
int		close_window(t_access *access);
int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);

#endif
