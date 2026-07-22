/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:33:01 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/22 15:49:32 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
// Selectively Color Pixels in Memory
void	put_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	offset;

	offset = (y * fractal->line_length) + (x * (fractal->bpp / 8));
	*(unsigned int *)(fractal->img_addr + offset) = color;
}

// Linear Interpolation (Scaling from Pixels to the Complex Plane)
double	map(double unscaled_num, double new_min,
			double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num / old_max) + new_min);
}
