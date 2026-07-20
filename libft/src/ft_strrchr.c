/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 01:36:07 by pabartoc          #+#    #+#             */
/*   Updated: 2026/05/29 15:08:05 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	str = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			str = (char *)(s + i);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%s", ft_strrchr("hellowhatwsup", 119));
// 	return (0);
// }
