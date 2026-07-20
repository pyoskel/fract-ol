/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 09:09:14 by pabartoc          #+#    #+#             */
/*   Updated: 2026/05/28 19:54:04 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (unsigned char *) dst;
	src_ptr = (const unsigned char *) src;
	if ((size_t)dst < (size_t)src)
	{
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	else if ((size_t)dst > (size_t)src)
	{
		while (len--)
			dst_ptr[len] = src_ptr[len];
	}
	return (dst);
}

// int	main(void)
// {
// 	char s[] = "abcdefg";

// 	printf("%s\n", ft_memmove(s + 2, s, 4));
// 	printf("%s\n", memmove(s + 2, s, 4));
// 	return (0);
// }

// int main(void)
// {
//     char buffer[] = "42Heilbronn";

//     printf("Vorher:  %s\n", buffer);

//     // Wir wollen "42" nehmen und es um 2 Stellen nach rechts verschieben,
//     // genau dorthin, wo aktuell "He" steht.
//     // src = buffer (zeigt auf die '4')
//     // dst = buffer + 2 (zeigt auf das 'H')
//     // len = 2 Bytes (Wir kopieren 2 Zeichen)

//     memmove(buffer + 2, buffer, 2);

//     printf("Nachher: %s\n", buffer); 
//     // Output: 4242lbronn

//     return (0);
// }