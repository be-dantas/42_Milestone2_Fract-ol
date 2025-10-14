/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:13:29 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/14 18:54:46 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	input_error(int flag)
{
	if (flag == 1)
	{
		write (1, "Inputs valids:\n", 15);
		write (1, "./fractol mandelbroot\n", 22);
		write (1, "./fractol julia 000 000\n", 24);
		exit(EXIT_FAILURE);
	}
	else if (flag == 2)
	{
		write (1, "Julia value is invalid. Exemples valids:\n", 41);
		write (1, "./fractol julia \n", 17);
		exit(EXIT_FAILURE);
	}
}

void	valid_input(int ac, char **av, t_access *acs)
{
	int	i;

	i = 0;
	if (ac == 1)
		input_error(1);
	if (ft_strncmp(av[1], "mandelbroot", 11) == 0 && ac == 2)
		acs->fract = 1;
	else if (ft_strncmp(av[1], "julia", 5) == 0 && ac == 4)
		acs->fract = valid_julia(ac, av);
	else
		input_error(1);
}
