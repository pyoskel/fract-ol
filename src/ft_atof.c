/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 05:59:13 by pabartoc          #+#    #+#             */
/*   Updated: 2026/07/20 06:15:20 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static double	get_fraction(const char *str)
{
	double	fraction;
	double	divisor;
	int		i;

	fraction = 0.0;
	divisor = 1.0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		fraction = fraction * 10.0 + (str[i] - '0');
		divisor *= 10.0;
		i++;
	}
	return (fraction / divisor);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		result += get_fraction(&str[i] + 1);
	return (sign * result);
}
