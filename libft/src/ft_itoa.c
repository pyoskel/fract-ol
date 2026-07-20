/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 05:03:01 by pabartoc          #+#    #+#             */
/*   Updated: 2025/08/29 08:45:23 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	size_t	len;

	nbr = n;
	if (nbr == 0)
		return (ft_strdup("0"));
	len = counter(nbr);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		result[len - 1] = (nbr % 10) + '0';
		len--;
		nbr /= 10;
	}
	if (len > 0)
		result[0] = '-';
	return (result);
}
