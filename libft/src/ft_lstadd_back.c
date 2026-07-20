/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:04:49 by pabartoc          #+#    #+#             */
/*   Updated: 2026/05/28 19:58:22 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
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

// // -------------------------------------------------------------
// // Das Hauptprogramm
// // -------------------------------------------------------------
// int main(void)
// {
//     // Wir starten mit einer leeren Liste!
//     t_list *mylist = NULL;

//     printf("--- LEERE LISTE ---\n");
//     print_list(mylist);

//     // 1. Wir erstellen den ersten Knoten und hängen ihn hinten an
//     t_list *node1 = malloc(sizeof(t_list));
//     node1->content = strdup("Knoten 1");
//     node1->next = NULL;

//     ft_lstadd_back(&mylist, node1);
//     printf("--- NACH DEM ERSTEN ft_lstadd_back ---\n");
//     print_list(mylist);

//     // 2. Wir erstellen einen zweiten Knoten und hängen ihn hinten an
//     t_list *node2 = malloc(sizeof(t_list));
//     node2->content = strdup("Knoten 2");
//     node2->next = NULL;

//     ft_lstadd_back(&mylist, node2);

//     printf("--- NACH DEM ZWEITEN ft_lstadd_back ---\n");
//     print_list(mylist);

//     // Speicher aufräumen
//     free(node1->content); free(node1);
//     free(node2->content); free(node2);

//     return (0);
// }

// // command
// // -------------------------------------------------------------
// // cc ft_lstadd_back.c ft_lstlast.c && ./a.out
// // -------------------------------------------------------------

// -------------------------------------------------------------
// with explanation
// -------------------------------------------------------------
// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last_node;

// 	// 1. Sicherheitsabfrage
// 	if (!lst || !new)
// 		return ;

// 	// 2. Sonderfall: Die Liste ist komplett leer
// 	if (*lst == NULL)
// 	{
// 		// Der neue Knoten wird zum ersten Knoten
// 		*lst = new;
// 		return ;
// 	}

// 	// 3. Normalfall: Suche das letzte Element und hänge "new" an
// 	last_node = ft_lstlast(*lst);
// 	last_node->next = new;
// }