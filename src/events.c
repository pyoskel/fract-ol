/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:04:09 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/23 00:51:24 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// Called when the ESC key is pressed or the X button in the window is clicked
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->window);
	destroy_display(fractal);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

// --- Called every time a key is pressed ---
// 65307 is the X11 keycode for the ESC key in Linux
// Left Arrow  = 65361  ||   w = 119
// Right Arrow = 65363  ||   a = 97
// Up Arrow    = 65362  ||   s = 115
// Down Arrow  = 65364  ||   d = 100
// Space = 32
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == KEY_ESC)
		close_handler(fractal);
	else if (keysym == KEY_LEFT || keysym == KEY_A)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == KEY_RIGHT || keysym == KEY_D)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == KEY_UP || keysym == KEY_W)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == KEY_DOWN || keysym == KEY_S)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == KEY_SPACE)
		fractal->color_shift += 5;
	fractal_render(fractal);
	return (EXIT_SUCCESS);
}

// --- Called every time the mouse scrolls ---
// Scroll up (Zoom In == 4)          -> Reduces the scale
// Scroll wheel down (Zoom Out == 5) -> Increases the scale
// Zoom follows the actual mouse position
// 1. Calculate the exact mathematical coordinates of the pixel under the mouse
// 2. Adjust the shift so that the point under the mouse remains fixed
// 3. Apply the zoom and redraw
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_r;
	double	mouse_i;
	double	zoom_factor;

	if (button == 4)
		zoom_factor = 0.95;
	else if (button == 5)
		zoom_factor = 1.05;
	else
		return (EXIT_SUCCESS);
	mouse_r = ((double)x / 800.0) * 5.0 - 3.0;
	mouse_i = ((double)y / 800.0) * -5.0 + 3.0;
	fractal->shift_x += mouse_r * fractal->zoom;
	fractal->shift_x -= mouse_r * (fractal->zoom * zoom_factor);
	fractal->shift_y += mouse_i * fractal->zoom;
	fractal->shift_y -= mouse_i * (fractal->zoom * zoom_factor);
	fractal->zoom *= zoom_factor;
	fractal_render(fractal);
	return (EXIT_SUCCESS);
}

// --- Log all events ---
// Event 17 (DestroyNotify): Responds to clicking the ‘X’ on the window
// Event 2 (KeyPress): Responds to every keystroke
//    (1L << 0) is the KeyPressMask, which tells the system what to listen for
void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->window, 17, 0, close_handler, fractal);
	mlx_hook(fractal->window, 2, (1L << 0), key_handler, fractal);
	mlx_mouse_hook(fractal->window, mouse_handler, fractal);
}
