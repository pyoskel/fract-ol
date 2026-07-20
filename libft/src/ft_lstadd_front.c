/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:00:57 by pabartoc          #+#    #+#             */
/*   Updated: 2026/05/28 19:59:22 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// void    print_list(t_list *lst)
// {
//     while (lst != NULL)
//     {
//         printf("[%s] -> ", (char *)lst->content);
//         lst = lst->next;
//     }
//     printf("NULL\n\n");
// }

// int main(void)
// {
//     // 1. Bauen unsere Listen (Knoten A und B)
//     t_list *nodeA = malloc(sizeof(t_list));
//     t_list *nodeB = malloc(sizeof(t_list));

//     nodeA->content = strdup("Knoten A");
//     nodeB->content = strdup("Knoten B");

//     nodeA->next = nodeB;
//     nodeB->next = NULL;

//     t_list *mylist = nodeA; // Hauptzeiger zeigt auf A

//     printf("--- VOR ft_lstadd_front ---\n");
//     print_list(mylist);

//     // -------------------------------------------------------------
//     // 2. Wir erstellen unseren NEUEN Knoten
//     // -------------------------------------------------------------
//     t_list *new_node = malloc(sizeof(t_list));
//     new_node->content = strdup("Knoten NEU");
//     new_node->next = NULL; // Zeigt vorerst ins Leere

//     // 3. Wir rufen die Funktion auf! 
//     // Wir übergeben die ADRESSE unseres Hauptzeigers (&mylist)
//     // und den neuen Knoten.
//     ft_lstadd_front(&mylist, new_node);

//     printf("--- NACH ft_lstadd_front ---\n");
//     print_list(mylist);

//     // -------------------------------------------------------------
//     // Speicher aufräumen (Damit wir saubere Programmierer bleiben)
//     // -------------------------------------------------------------
//     free(nodeA->content); free(nodeA);
//     free(nodeB->content); free(nodeB);
//     free(new_node->content); free(new_node);

//     return (0);
// }