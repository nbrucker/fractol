/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:57:11 by nbrucker          #+#    #+#             */
/*   Updated: 2018/03/20 17:57:12 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color1(int i)
{
	int color[5];

	color[0] = 0xa81fb4;
	color[1] = 0x7ff2df;
	color[2] = 0xeebca0;
	color[3] = 0x7ad5f1;
	color[4] = 0x161561;
	return (color[i]);
}

int		color2(int i)
{
	int color[5];

	color[0] = 0x5c0d2d;
	color[1] = 0x3d99c2;
	color[2] = 0x3acde1;
	color[3] = 0xe08d1c;
	color[4] = 0x5cb36f;
	return (color[i]);
}

int		color3(int i)
{
	int color[5];

	color[0] = 0x1ab5e6;
	color[1] = 0xf5a973;
	color[2] = 0xfc80da;
	color[3] = 0x70afe0;
	color[4] = 0x0c8d7c;
	return (color[i]);
}

int		color4(int i)
{
	int color[5];

	color[0] = 0xe00950;
	color[1] = 0xab5935;
	color[2] = 0x4fd8c6;
	color[3] = 0x8bd244;
	color[4] = 0x310774;
	return (color[i]);
}

int		ft_color(int i, t_env *env)
{
	if (env->color == 0)
		return (i * 255 / env->max);
	else if (env->color == 1)
		return (color1(i % 5));
	else if (env->color == 2)
		return (color2(i % 5));
	else if (env->color == 3)
		return (color3(i % 5));
	else if (env->color == 4)
		return (color4(i % 5));
	return (0);
}
