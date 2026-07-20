/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 00:59:23 by pabartoc          #+#    #+#             */
/*   Updated: 2025/07/13 03:11:55 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	printf("%d\n", ft_isdigit('2'));
// 	printf("%d\n", ft_isdigit('a'));
// 	printf("%d\n", ft_isdigit(50));
// 	return (0);
// }