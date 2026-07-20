/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 06:55:38 by pabartoc          #+#    #+#             */
/*   Updated: 2025/08/27 02:24:40 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *) haystack);
	i = 0;
	while (haystack[i] != '\0' && i + needle_len <= len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *) &haystack[i]);
		i++;
	}
	return (NULL);
}
