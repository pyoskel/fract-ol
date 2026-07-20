/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 06:55:59 by pabartoc          #+#    #+#             */
/*   Updated: 2025/08/27 07:04:38 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp_ptr;
	size_t			total;

	total = count * size;
	tmp_ptr = malloc(count * size);
	if (!tmp_ptr)
		return (NULL);
	ft_memset(tmp_ptr, 0, total);
	return (tmp_ptr);
}
