/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:21:25 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/10/13 10:18:43 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_access
{
	void	*mlx_connection;
	void	*mlx_window;
	void	*img;
	char	*img_pointer;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_access;

typedef struct s_zoom
{
    double  zoom;      // começa em 1.0
    double  coordenada_x;  // começa em 0.0  
    double  coordenada_y;  // começa em 0.0
    int     max_iter;
}	t_zoom;

# endif
