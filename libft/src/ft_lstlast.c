/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:01:20 by pabartoc          #+#    #+#             */
/*   Updated: 2026/05/29 14:59:02 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// -------------------------------------------------------------
// with explanation
// -------------------------------------------------------------

// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (!lst)
//         return (NULL);
// 	// Solange der Zeiger Wahr / ungleich 0 ist
//     while (lst->next)
//         lst = lst->next;
//     return (lst);
// }
