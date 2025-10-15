/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand_and_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:18:14 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/10/15 13:09:34 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	if_mandelbroot(t_access *acs)
{
	double	a;
	double	b;
	double	a2;
	double	b2;
	int		i;

	a = 0.0;
	b = 0.0;
	a2 = 0.0;
	b2 = 0.0;
	i = 0;
	while (i < acs->max_iter)
	{
		a2 = a * a;
		b2 = b * b;
		if (a2 + b2 > 4.0)
			return (i);
		b = 2 * a * b + acs->im;
		a = a2 - b2 + acs->re;
		i++;
	}
	return (acs->max_iter);
}

int	if_julia(t_access *acs)
{
	double	a;
	double	b;
	int		i;
	double	temp;

	a = acs->re;
	b = acs->im;
	i = 0;
	while (i < acs->max_iter && (a * a + b * b <= 4.0))
	{
		temp = a * a - b * b + acs->j1;
		b = 2 * a * b + acs->j2;
		a = temp;
		i++;
	}
	if (i == acs->max_iter)
		return (acs->max_iter);
	else
		return (i);
}
