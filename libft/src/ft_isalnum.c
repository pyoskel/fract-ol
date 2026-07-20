/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 04:18:13 by pabartoc          #+#    #+#             */
/*   Updated: 2025/07/13 03:19:31 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	printf("%d\n", ft_isalnum('*'));
// 	printf("%d\n", ft_isalnum('2'));
// 	printf("%d\n", ft_isalnum(';'));
// 	printf("%d\n", ft_isalnum('B'));
// 	printf("%d\n", ft_isalnum('\\'));
// 	printf("%d\n", ft_isalnum('c'));
// 	printf("%d\n", ft_isalnum('|'));
// }
