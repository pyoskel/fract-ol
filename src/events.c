/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:04:09 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/21 10:17:12 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// Called when the ESC key is pressed or the X button in the window is clicked
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

// --- Called every time a key is pressed ---
// 65307 is the X11 keycode for the ESC key in Linux
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 65307)
		close_handler(fractal);
	return (EXIT_SUCCESS);
}

// --- Log all events ---
// Event 17 (DestroyNotify): Responds to clicking the ‘X’ on the window

// Event 2 (KeyPress): Responds to every keystroke
// (1L<<0) is the KeyPressMask, which tells the system what to listen for
void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->window, 17, 0, close_handler, fractal);
	mlx_hook(fractal->window, 2, (1L<<0), key_handler, fractal);
}
