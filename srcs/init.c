/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:07:17 by nbrucker          #+#    #+#             */
/*   Updated: 2018/03/20 18:07:17 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"

void	ft_init_mlx(t_env *env)
{
	int		bpp;
	int		s_l;
	int		endian;

	if ((env->mlx = mlx_init()) == NULL)
		ft_error("MLX Error");
	if ((env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "fractol")) == NULL)
		ft_error("MLX Error");
	if ((env->image = mlx_new_image(env->mlx, WIDTH, HEIGHT)) == NULL)
		ft_error("MLX Error");
	if ((env->str = mlx_get_data_addr(env->image, &bpp, &s_l, &endian)) == NULL)
		ft_error("MLX Error");
}

void	ft_init_env_next(t_env *env)
{
	if (env->type == 3)
	{
		env->x = -2.05;
		env->y = -1.32;
		env->zoom = 250;
		env->max = 50;
	}
	else if (env->type == 4)
	{
		env->x = -2.3;
		env->y = -1.55;
		env->zoom = 200;
		env->max = 50;
	}
	else if (env->type == 5)
	{
		env->x = -2;
		env->y = -1.75;
		env->zoom = 250;
		env->max = 50;
	}
}

void	ft_init_env(t_env *env)
{
	env->block = 0;
	env->color = 0;
	if (env->type == 1)
	{
		env->x = -2.1;
		env->y = -1;
		env->zoom = 300;
		env->max = 50;
	}
	else if (env->type == 2)
	{
		env->x = -2.1;
		env->y = -1.5;
		env->zoom = 200;
		env->max = 150;
		env->c_r = 0.285;
		env->c_i = 0.01;
	}
	else
		ft_init_env_next(env);
}
