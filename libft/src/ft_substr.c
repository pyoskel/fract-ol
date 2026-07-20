/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 00:11:28 by pabartoc          #+#    #+#             */
/*   Updated: 2025/08/28 02:21:34 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	if (start >= s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = *(s + start + i);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// test for len > s_len - start
// s_len = 13;
// start = 8;
// len = 7;

// if (7 > 13 - 8)
// if (7 > 5)
// if (5 = 5)

// 	substr = ft_substr(str, 8, 7);
// 	printf("Substring: '%s'\n", substr); // Erwartet: 'orld!'
// free (substr);

// int	main(void)
// {
// 	char *str = "Hello, World!";
// 	char *substr;

// 	substr = ft_substr(str, 7, 5);
// 	printf("Substring: '%s'\n", substr); // Erwartet: 'World'
// 	free(substr);

// 	substr = ft_substr(str, 0, 5);
// 	printf("Substring: '%s'\n", substr); // Erwartet: 'Hello'
// 	free(substr);

// 	substr = ft_substr(str, 20, 5);
// 	printf("Substring: '%s'\n", substr); // Erwartet: ''
// 	free(substr);

// 	return (0);
// }