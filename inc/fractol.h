/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 01:59:58 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/21 10:31:52 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* --- Standard Libraries --- */
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
	// Variables Specific to Julia
	double	julia_x;		// real part		(av[2])
	double	julia_y;		// imaginary part (av[3])
}			t_fractal;

/* --- Function Prototypes --- */

// events.c
int		close_handler(t_fractal *fractal);
int		key_handler(int keysym, t_fractal *fractal);
void	events_init(t_fractal *fractal);

// ft_atof.c
double	ft_atof(const char *str);

// init.c
void	fractal_init(t_fractal *fractal);

// validation.c
int		is_double_valid(char *str);

#endif