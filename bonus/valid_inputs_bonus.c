/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_inputs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:13:29 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/16 14:46:09 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	input_error(int flag)
{
	if (flag == 1)
	{
		write (1, "Inputs valids:\n", 15);
		write (1, "./fractol mandelbrot\n", 21);
		write (1, "./fractol julia 000 000\n", 24);
		exit(EXIT_FAILURE);
	}
	else if (flag == 2)
	{
		write (1, "Julia value is invalid. Exemples valids:\n", 41);
		write (1, "./fractol julia 0.355 0.355\n", 28);
		write (1, "./fractol julia -0.4 0.6\n", 25);
		write (1, "./fractol julia -0.8 0.156\n", 27);
		write (1, "./fractol julia 0.258 0.01\n", 27);
		exit(EXIT_FAILURE);
	}
}

int	valid_julia(char **av, t_access *acs)
{
	int			res_s1;
	int			res_s2;

	res_s1 = ft_is_double(av[2]);
	res_s2 = ft_is_double(av[3]);
	if (res_s1 == 0 || res_s2 == 0)
		input_error(2);
	if (res_s1 == 1)
		acs->j1 = (double)ft_atoi(av[2]);
	else if (res_s1 == 2)
		acs->j1 = ft_atof(av[2]);
	if (res_s2 == 1)
		acs->j2 = (double)ft_atoi(av[3]);
	else if (res_s2 == 2)
		acs->j2 = ft_atof(av[3]);
	return (2);
}

int	valid_input(int ac, char **av, t_access *acs)
{
	if (ac == 1)
		input_error(1);
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0 && ac == 2)
		return (1);
	else if (ft_strncmp(av[1], "julia", 6) == 0 && ac == 4)
		return (valid_julia(av, acs));
	else
		input_error(1);
	return (0);
}
