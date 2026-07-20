/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 22:14:46 by pabartoc          #+#    #+#             */
/*   Updated: 2025/08/30 17:06:31 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static void	*let_split_free(char **array, size_t w)
{
	while (w > 0)
	{
		w--;
		free(array[w]);
	}
	free(array);
	return (NULL);
}

static char	**copy_word(char **array, char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	w;

	i = 0;
	len = 0;
	w = 0;
	while (1)
	{
		if (s[i] != '\0' && s[i] != c)
			len++;
		else if ((i != 0 && s[i - 1] != c) && (s[i] == c || s[i] == '\0'))
		{
			array[w] = ft_substr(s, i - len, len);
			if (!array[w])
				return (let_split_free(array, w), NULL);
			w++;
			len = 0;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	array_size;

	if (!s)
		return (NULL);
	array_size = count_words(s, c);
	array = (char **)ft_calloc(array_size + 1, sizeof(char *));
	if (!array)
		return (NULL);
	return (copy_word(array, s, c));
}

// char	c = ' ';
// char *s = "Hello my Name is Pascal";
// count_words[5];
// word_array[0][5];

// int	main(void)			//count_words	main function
// {
// 	char	c = '|';
// 	char	*s = "|||One|||tWo|thRee||FouR|||||";

// 	printf("%zu\n", count_words(s, c));
// 	return (0);
// }

// int	main(void)			//copy_word	main function
// {
// 	char	c = '|';
// 	char	*s = "|||One|||tWo|thRee||FouR|||||Pi";
// 	char	**array = ft_split(s, c);
// 	int		i = 0;

// 	while (array[i] != NULL)
// 	{
// 		printf("%s\v", array[i]);
// 		i++;
// 	}
// 	return (0);
// }
