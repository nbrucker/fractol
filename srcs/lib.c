/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:15:12 by nbrucker          #+#    #+#             */
/*   Updated: 2018/03/20 18:15:12 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

int		ft_expose(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
	return (0);
}

void	ft_fill_pixel(t_env *env, int x, int y, int color)
{
	int i;

	i = ((y * WIDTH) + x) * 4;
	if (i < 0 || i >= WIDTH * HEIGHT * 4)
		return ;
	env->str[i] = color & 0xFF;
	env->str[i + 1] = (color >> 8) & 0xFF;
	env->str[i + 2] = (color >> 16) & 0xFF;
}

int		ft_exit(t_env *env)
{
	(void)env;
	exit(0);
	return (0);
}
