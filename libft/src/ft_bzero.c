/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:37:56 by pabartoc          #+#    #+#             */
/*   Updated: 2025/07/23 23:34:02 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n > 0)
	{
		*ptr++ = 0;
		n--;
	}
}

// int	main(void)
// {
// 	char str[42] = "Komm in die Gruppe!!!";

// 	ft_bzero(str, 5);
// 	printf("%s\n", str + 5);
// 	return (0);
// }
