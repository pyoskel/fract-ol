/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 02:10:13 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/21 10:32:14 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "libft.h"

// ./fractol mandelbrot       | ac == 2
// ./fractol julia -0.4 0.6.  | ac == 4

// Real part      = av[2] == x
// Imaginary part = av[3] == y
// You must be able to create different Julia sets by passing
// different parameters to the program

static int	print_help(void)
{
	ft_putstr_fd("\nInvalid input!\n\n", 1);
	ft_putstr_fd("Allowed parameters:\n", 1);
	ft_putstr_fd("1. ./fractol mandelbrot\n", 1);
	ft_putstr_fd("2. ./fractol julia <real> <imaginary>\n", 1);
	ft_putstr_fd("Example: ./fractol julia -0.4 0.6\n\n", 1);
	return (EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
		fractal.name = av[1];
	else if (ac == 4 && ft_strncmp(av[1], "julia", 6) == 0)
	{
		if (!is_double_valid(av[2]) || !is_double_valid(av[3]))
			return (print_help());
		fractal.name = av[1];
		fractal.julia_x = ft_atof(av[2]);
		fractal.julia_y = ft_atof(av[3]);
	}
	else
		return (print_help());
	fractal_init(&fractal);
	events_init(&fractal);
	mlx_loop(fractal.mlx);
	return (EXIT_SUCCESS);
}

// --- First Version ---
// ----------------------------------------------------------
// int	main(int ac, char **av)
// {
// 	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
// 	{
// 		printf("passed mandelbrot ✅\n");
// 		printf("Test 1: ac = 2\n");
// 	}
// 	else if (ac == 4 && ft_strncmp(av[1], "julia", 6) == 0)
// 	{
// 		if (!is_double_valid(av[2]) || !is_double_valid(av[3]))
// 		{
// 			printf("Error: Incorrect number!\n");
// 			printf("Usage: ./fractol julia '-0.42' '0.42'\n");
// 			return (EXIT_FAILURE);
// 		}
// 		double julia_real;
// 		double julia_imaginary;

// 		julia_real = ft_atof(av[2]);
// 		julia_imaginary = ft_atof(av[3]);

// 		printf("av[2] ✅ %f\n", julia_real);
// 		printf("av[3] ✅ %f\n", julia_imaginary);
// 		printf("passed julia ✅\n");
// 		printf("Test 2: ac = 4\n");
// 	}
// 	else
// 		return (EXIT_FAILURE, printf("Error\n"));
// 	return (0);
// }
