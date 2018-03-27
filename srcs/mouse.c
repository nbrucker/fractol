/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:25:53 by nbrucker          #+#    #+#             */
/*   Updated: 2018/03/20 18:25:54 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_move(int x, int y, t_env *env)
{
	if (env->type != 2)
		return (0);
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	env->c_r = (((double)x / (double)WIDTH) * 3.5) - 2.5;
	env->c_i = (((double)y / (double)HEIGHT) * 2) - 1;
	ft_fractol(env);
	return (0);
}

int		ft_mouse_click(int key, int x, int y, t_env *env)
{
	double	scale_x;
	double	scale_y;
	double	factor_x;
	double	factor_y;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	scale_x = (double)x / WIDTH;
	scale_y = (double)y / HEIGHT;
	factor_x = WIDTH * 0.1;
	factor_y = HEIGHT * 0.1;
	if (key == 1 || key == 4)
	{
		env->y += (1 / (env->zoom / factor_y)) * scale_y;
		env->x += (1 / (env->zoom / factor_x)) * scale_x;
		env->zoom *= 1.1;
	}
	else if (key == 2 || key == 5)
	{
		env->y -= (1 / (env->zoom / factor_y)) * scale_y;
		env->x -= (1 / (env->zoom / factor_x)) * scale_x;
		env->zoom /= 1.1;
	}
	ft_fractol(env);
	return (0);
}
