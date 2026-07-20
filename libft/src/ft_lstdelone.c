/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:05:25 by pabartoc          #+#    #+#             */
/*   Updated: 2026/05/29 14:57:46 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del_content(void *content)
// {
// 	// Da unser Inhalt in der main() mit strdup (also malloc) 
// 	// erstellt wird, reicht hier ein einfaches free().
// 	free(content);
// 	printf(" -> Der ersten Listen-Inhalt wurde freigegeben!\n");
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	// Wenn es den Knoten oder die Löschfunktion nicht gibt, mach nichts
// 	if (!lst || !del)
// 		return ;

// 	// 1. Lösche den Inhalt des Knotens
// 	del(lst->content);

// 	// 2. Lösche die Hülle (den Knoten selbst)
// 	free(lst);
// }

// int main(void)
// {
//     // 1. Liste aufbauen
//     t_list  *node1 = malloc(sizeof(t_list));
//     t_list  *node2 = malloc(sizeof(t_list));
//     t_list  *node3 = malloc(sizeof(t_list));

//     node1->content = strdup("Erstes Element");
//     node2->content = strdup("Zweites Element");
//     node3->content = strdup("Drittes Element");

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     t_list *mylist = node1;

//     // -------------------------------------------------------------
//     // SCHRITT 1: Element 1 isolieren und löschen
//     // -------------------------------------------------------------
//     printf("--- LOESCHE ELEMENT 1 ---\n");

//     mylist = node1->next; // mylist auf node2 schieben
//     ft_lstdelone(node1, del_content);

//     // -------------------------------------------------------------
//     // SCHRITT 2: Den Rest der Liste manuell in einer Schleife löschen
//     // -------------------------------------------------------------
//     printf("\n--- LOESCHE DEN REST DER LISTE ---\n");

//     t_list *tmp; // Hilfsvariable zum Retten der Zeiger

//     // Solange mylist nicht NULL ist (wir also noch Knoten haben)
//     while (mylist != NULL)
//     {
//         // 1. Adresse des nächsten Knotens retten!
//         tmp = mylist->next;

//         // 2. Den aktuellen Knoten gefahrlos löschen
//         ft_lstdelone(mylist, del_content);

//         // 3. Unseren Hauptzeiger auf den geretteten, nächsten Knoten setzen
//         mylist = tmp;
//     }

//     // -------------------------------------------------------------
//     // KONTROLLE
//     // -------------------------------------------------------------
//     if (mylist == NULL)
//         printf("\nErfolg! Alles restlos gelöscht. Keine Memory Leaks!\n");

//     return (0);
// }
