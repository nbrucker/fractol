/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:34:01 by nbrucker          #+#    #+#             */
/*   Updated: 2018/03/28 14:34:02 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_burningship(int x, int y, t_env *env)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		i;

	c_r = x / env->zoom + env->x;
	c_i = y / env->zoom + env->y;
	z_r = 0;
	z_i = 0;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < env->max)
	{
		env->tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * ft_abs(z_i) * ft_abs(env->tmp) + c_i;
		i++;
	}
	if (i == env->max)
		ft_fill_pixel(env, x, y, 0x000000);
	else
		ft_fill_pixel(env, x, y, ft_color(i, env));
}
