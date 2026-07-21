/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 04:38:52 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/21 09:27:14 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// Establishes the connection to the MLX, the window, and the image
void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		exit(EXIT_FAILURE);
	fractal->window = mlx_new_window(fractal->mlx, 800, 800, fractal->name);
	if (fractal->window == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit(EXIT_FAILURE);
	}
	fractal->img = mlx_new_image(fractal->mlx, 800, 800);
	if (fractal->img == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		exit(EXIT_FAILURE);
	}
	fractal->img_addr = mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->line_length, &fractal->endian);
}
