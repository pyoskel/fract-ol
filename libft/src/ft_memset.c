/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 04:19:33 by pabartoc          #+#    #+#             */
/*   Updated: 2025/08/15 18:47:47 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	while (len > 0)
	{
		*ptr = (unsigned char) c;
		ptr++;
		len--;
	}
	return (b);
}

// int	main(void)
// {
// 	char str[50] = "Hallo Welt!";
// 	ft_memset(str, 'X', 5); // Überschreibe die ersten 10 Bytes mit 'X'
// 	printf("%s\n", str); // Ausgabe: "XXXXX Welt!"
// 	return (0);
// }