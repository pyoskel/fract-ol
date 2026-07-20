/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 01:38:14 by pabartoc          #+#    #+#             */
/*   Updated: 2025/08/26 05:06:46 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((unsigned char) s[i] == (unsigned char) c)
		return ((char *) &s[i]);
	return (NULL);
}
