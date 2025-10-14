/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:13:29 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/14 12:13:41 by bedantas         ###   ########.fr       */
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
