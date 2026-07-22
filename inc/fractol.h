/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 01:59:58 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/23 00:54:36 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* --- Standard Libraries --- */
# include "libft.h"
# include <mlx.h>	 // for minilibx
# include <stdlib.h> // for free and exit
# include <unistd.h> // for write
# include <limits.h> // for INT_MAX and INT_MIN
# include <stdio.h>  // IMPORTANT: For printf during testing!

typedef struct s_fractal
{
	char	*name;			// "mandelbrot" or "julia"
	// MLX Variables
	void	*mlx;			// Pointer to the MLX instance
	void	*window;		// Pointer to the window
	void	*img;			// Pointer to the Picture
	char	*img_addr;		// Memory address of the pixels
	int		bpp;			// Bits per pixel
	int		line_length;
	int		endian;
	// Variables for Fractal Mapping
	double	zoom;			// Zoom-Level
	double	shift_x;		// Translation along the X-axis
	double	shift_y;		// Translation along the Y-axis
	int		max_iter;		// When the calculation stops
	int		color_shift;	// Shifts the colors by 5 units
	double	c_r;			// constant_real part
	double	c_i;			// constant_imaginary part
	// Variables Specific to Julia
	double	julia_x;		// real part		(av[2])
	double	julia_y;		// imaginary part (av[3])
}			t_fractal;

# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_SPACE 32

# elif defined (__APPLE__)
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_SPACE 49
# endif

/* --- Function Prototypes --- */

// events.c
int		close_handler(t_fractal *fractal);
int		key_handler(int keysym, t_fractal *fractal);
void	events_init(t_fractal *fractal);

// ft_atof.c
double	ft_atof(const char *str);

// init.c
void	fractal_init(t_fractal *fractal);

// render.c
void	fractal_render(t_fractal *fractal);

// utils.c
void	put_pixel(t_fractal *fractal, int x, int y, int color);
double	map(double unscaled_num, double new_min,
			double new_max, double old_max);

// validation.c
int		is_double_valid(char *str);

#endif