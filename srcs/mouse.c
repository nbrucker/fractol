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
	(void)env;
	(void)key;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	env->zoom += 10;
	env->x += 0;
	env->y += 0;
	ft_fractol(env);
	return (0);
}
