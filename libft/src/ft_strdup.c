/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 07:24:33 by pabartoc          #+#    #+#             */
/*   Updated: 2025/08/27 07:51:34 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp_ptr;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	tmp_ptr = malloc((i + 1) * sizeof(char));
	if (!tmp_ptr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		tmp_ptr[i] = s1[i];
		i++;
	}
	tmp_ptr[i] = '\0';
	return (tmp_ptr);
}
