/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 02:10:13 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/20 05:21:56 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "libft.h"

// ./fractol mandelbrot       | ac == 2
// ./fractol julia -0.4 0.6.  | ac == 4

// You must be able to create different Julia sets by passing
// different parameters to the program

int	main(int ac, char **av)
{
	if (ac == 1)
		printf("Test 1: ac = 1\n");
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
	{
		printf("%d\n", ft_strncmp(av[1], "mandelbrot", 11));
		printf("Test 2: ac = 2\n");	
	}
	// else if (ac == 4 && julia set)
	// {
		
	// }
	return (0);
}
