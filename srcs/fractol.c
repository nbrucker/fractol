/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:58:20 by nbrucker          #+#    #+#             */
/*   Updated: 2018/03/20 17:58:21 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(int x, int y, t_env *env)
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
		z_i = 2 * z_i * env->tmp + c_i;
		i++;
	}
	if (i == env->max)
		ft_fill_pixel(env, x, y, 0x000000);
	else
		ft_fill_pixel(env, x, y, ft_color(i, env));
}

void	ft_julia(int x, int y, t_env *env)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	int		i;

	c_r = env->c_r;
	c_i = env->c_i;
	z_r = x / env->zoom + env->x;
	z_i = y / env->zoom + env->y;
	i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < env->max)
	{
		env->tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * env->tmp + c_i;
		i++;
	}
	if (i == env->max)
		ft_fill_pixel(env, x, y, 0x000000);
	else
		ft_fill_pixel(env, x, y, ft_color(i, env));
}

void	ft_poulet(int x, int y, t_env *env)
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
		z_i = ft_abs(2 * z_i * env->tmp + c_i);
		i++;
	}
	if (i == env->max)
		ft_fill_pixel(env, x, y, 0x000000);
	else
		ft_fill_pixel(env, x, y, ft_color(i, env));
}

void	ft_tricorn(int x, int y, t_env *env)
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
		z_i *= -1;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * env->tmp + c_i;
		i++;
	}
	if (i == env->max)
		ft_fill_pixel(env, x, y, 0x000000);
	else
		ft_fill_pixel(env, x, y, ft_color(i, env));
}

void	ft_fractol(t_env *env)
{
	int x;
	int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (env->type == 1)
				ft_mandelbrot(x, y, env);
			else if (env->type == 2)
				ft_julia(x, y, env);
			else if (env->type == 3)
				ft_poulet(x, y, env);
			else if (env->type == 4)
				ft_tricorn(x, y, env);
			y++;
		}
		x++;
	}
	ft_expose(env);
}
