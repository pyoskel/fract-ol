/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:48:41 by pabartoc          #+#    #+#             */
/*   Updated: 2025/07/21 23:41:37 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_isalpha('6'));
// 	printf("%d\n", ft_isalpha('a'));
// 	printf("%d\n", ft_isalpha(121));
// 	return (0);
// }