/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:41:05 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/23 00:53:48 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// For Burningship
static double	ft_abs_value_double(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

// RGB format (Red, Green, Blue): 0xRRGGBB
// Pure red is: 0xFF0000
// Pure green is: 0x00FF00
// Pure blue is: 0x0000FF
// Purple (a mixture of a lot of red, a little green, and a lot of blue) is,
// for example: 0x800080 or, in a lighter shade, 0xA020F0.
// dynamic color palette:
// ((i * 13 % 256) << 16) | ((i * 4 % 256) << 8) | (i * 18 % 256)
//             RED << 16  |          GREEN << 8  |          BLUE
static void	put_color(int x, int y, int i, t_fractal *fractal)
{
	if (i == fractal->max_iter)
		put_pixel(fractal, x, y, 0x4A2E04);
	else
		put_pixel(fractal, x, y,
			(((i + fractal->color_shift) * 13 % 256) << 16)
			| (((i + fractal->color_shift) * 4 % 256) << 8)
			| ((i + fractal->color_shift) * 18 % 256));
}

// Assign initial values for the Mandelbrot or Julia sets
static void	set_z_c(double *z_r, double *z_i, t_fractal *fractal)
{
	if (ft_strncmp(fractal->name, "julia", 6) == 0)
	{
		fractal->c_r = fractal->julia_x;
		fractal->c_i = fractal->julia_y;
	}
	else
	{
		fractal->c_r = *z_r;
		fractal->c_i = *z_i;
		*z_r = 0.0;
		*z_i = 0.0;
	}
}

// --- The mathematical calculation for ONE pixel ---
static void	render_pixel(int x, int y, t_fractal *fractal)
{
	double	z_r;
	double	z_i;
	double	tmp_r;
	int		i;

	z_r = (map(x, -2, +2, 800) * fractal->zoom) + fractal->shift_x;
	z_i = (map(y, +2, -2, 800) * fractal->zoom) + fractal->shift_y;
	set_z_c(&z_r, &z_i, fractal);
	i = 0;
	while (i < fractal->max_iter)
	{
		if (fractal->name[0] == 'b')
		{
			z_r = ft_abs_value_double(z_r);
			z_i = ft_abs_value_double(z_i);
		}
		tmp_r = (z_r * z_r) - (z_i * z_i);
		z_i = 2 * z_r * z_i + fractal->c_i;
		z_r = tmp_r + fractal->c_r;
		if ((z_r * z_r) + (z_i * z_i) > 4.0)
			break ;
		i++;
	}
	put_color(x, y, i, fractal);
}

// The rendering loop (goes through every pixel in the window)
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			render_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img, 0, 0);
}

// TEST-AUSGABE für den Pixel exakt in der Bildschirmmitte (x: 400, y: 400)
		// if (x == 500 && y == 400)
		// {
		// 	printf("Iter %d: z_r = %f, z_i = %f | Abstand² = %f\n", 
		// 			i, z_r, z_i, (z_r * z_r) + (z_i * z_i));
		// }