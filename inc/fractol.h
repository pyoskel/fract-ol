/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 01:59:58 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/21 05:26:01 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* --- Standard Libraries --- */
# include <stdlib.h> // for malloc and free
# include <unistd.h> // for write
# include <limits.h> // for INT_MAX and INT_MIN
# include <stdio.h> // IMPORTANT: For printf during testing!

typedef struct s_fractal
{
	char 	*name;		  // "mandelbrot" or "julia"
// Variables Specific to Julia
	double	julia_x;      // real part		(av[2])
	double	julia_y;      // imaginary part (av[3])
}			t_fractal;

/* --- Function Prototypes --- */
// ft_atof.c
double	ft_atof(const char *str);

// validation.c
int	is_double_valid(char *str);

#endif