/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:33:03 by nbrucker          #+#    #+#             */
/*   Updated: 2018/03/20 16:33:03 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "mlx.h"

int		ft_input(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key >= 82 && key <= 86)
		env->color = key - 82;
	else if (key == 69)
		env->max += 10;
	else if (key == 78)
		env->max -= 10;
	else if (key >= 18 && key <= 22)
	{
		env->type = key - 17;
		ft_init_env(env);
	}
	else if (key == 124)
		env->x -= (1 / (env->zoom / 10));
	else if (key == 123)
		env->x += (1 / (env->zoom / 10));
	else if (key == 126)
		env->y += (1 / (env->zoom / 10));
	else if (key == 125)
		env->y -= (1 / (env->zoom / 10));
	else if (key == 35)
		env->block = (env->block == 0) ? 1 : 0;
	ft_fractol(env);
	return (0);
}

void	ft_usage(void)
{
	ft_putendl("./fractol [name]");
	ft_putstr("mandelbrot");
	ft_putstr(" | ");
	ft_putstr("julia");
	ft_putstr(" | ");
	ft_putstr("poulet");
	ft_putstr(" | ");
	ft_putstr("tricorn");
	ft_putstr(" | ");
	ft_putstr("burningship");
	ft_error("");
}

void	ft_get_type(char *name, t_env *env)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		env->type = 1;
	else if (ft_strcmp(name, "julia") == 0)
		env->type = 2;
	else if (ft_strcmp(name, "poulet") == 0)
		env->type = 3;
	else if (ft_strcmp(name, "tricorn") == 0)
		env->type = 4;
	else if (ft_strcmp(name, "burningship") == 0)
		env->type = 5;
	else
		ft_usage();
}

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		ft_usage();
	ft_get_type(argv[1], &env);
	ft_init_mlx(&env);
	ft_init_env(&env);
	ft_fractol(&env);
	mlx_hook(env.win, 2, 3, ft_input, &env);
	mlx_mouse_hook(env.win, ft_mouse_click, &env);
	mlx_hook(env.win, 6, (1L << 6), ft_mouse_move, &env);
	mlx_hook(env.win, 17, 1L << 17, ft_exit, &env);
	mlx_expose_hook(env.win, ft_expose, &env);
	mlx_loop(env.mlx);
	return (0);
}
