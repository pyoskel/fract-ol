/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 02:28:17 by pabartoc          #+#    #+#             */
/*   Updated: 2025/08/28 03:18:09 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	total_str;
	size_t	i;
	size_t	n;

	total_str = (ft_strlen(s1) + ft_strlen(s2));
	result = malloc((total_str + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[i] != '\0')
		result[n++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		result[n++] = s2[i++];
	result[n] = '\0';
	return (result);
}
