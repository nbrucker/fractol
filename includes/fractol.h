/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:34:05 by nbrucker          #+#    #+#             */
/*   Updated: 2018/03/20 16:34:05 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct	s_env
{
	int			type;
	int			max;
	double		y;
	double		x;
	double		c_r;
	double		c_i;
	double		zoom;
	void		*mlx;
	void		*win;
	void		*image;
	char		*str;
	double		tmp;
	int			color;
}				t_env;

void			ft_fractol(t_env *env);
int				ft_color(int i, t_env *env);
int				ft_expose(t_env *env);
void			ft_fill_pixel(t_env *env, int x, int y, int color);
void			ft_init_mlx(t_env *env);
void			ft_init_env(t_env *env);
int				ft_exit(t_env *env);
int				ft_mouse_move(int x, int y, t_env *env);
int				ft_mouse_click(int key, int x, int y, t_env *env);

#endif
