/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:53:14 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/14 18:42:45 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_double(char *av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (av[i] == '.')
			j++;
		i++;
	}
	if (j >= 0 && j <= 1 || av[0] == '.' || av[i - 1] == '.')
		return (0);
	i = 0;
	while (av[i])
	{
		if (av[i] >= 0 && av[i] <= 9 || av[i] == '.')
			i++;
		else
			return (0);
	}
	if (j == 0)
		return (1);
	if (j == 1)
		return (2);
}

double	for_double(int atoi, char *av)
{
	int	i;
	int	decimal;

	i = 0;
	decimal = 1;
	while (av[i] != '.')
		i++;
	i++;
	while (av[i])
	{
		decimal = decimal * 10;
		i++;
	}
	return (atoi / decimal);
}

double	atoi_double(char *av)
{
	int		i;
	char	**split_av;
	char	*join_av;
	int		atoi_av;
	double	result;

	i = 0;
	split_av = ft_split(av, '.');
	join_av = (split_av[1], split_av[2]);
	atoi_av = ft_atoi(join_av);
	while (split_av[i])
	{
		free(split_av[i]);
		i++;
	}
	free(split_av);
	free(join_av);
	result = for_double(atoi_av, av);
	return (result);
}

int	valid_julia(int ac, char **av)
{
	t_access	acs;
	int			res_s1;
	int			res_s2;

	res_s1 = is_double(av[2]);
	res_s2 = is_double(av[3]);
	if (res_s1 != 0 && res_s1 != 0)
	{
		if (res_s1 == 1)
			acs.j1 = (double)ft_atoi(av[2]);
		else if (res_s2 == 2)
			acs.j1 = atoi_double(av[2]);
		if (res_s2 == 1)
			acs.j2 = (double)ft_atoi(av[3]);
		else if (res_s2 == 2)
			acs.j2 = atoi_double(av[3]);
		return (2);
	}
	else
		input_error(2);
}
