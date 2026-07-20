/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:06:02 by pabartoc          #+#    #+#             */
/*   Updated: 2026/05/29 14:56:22 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// Function with explainations
// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*tmp;

// 	// Sicherheitsabfrage: Wenn der Doppelzeiger oder
//  // die Löschfunktion nicht existieren, abbrechen
// 	if (!lst || !del)
// 		return ;

// 	// Solange der Zeiger auf das aktuelle Element nicht NULL ist
// 	while (*lst)
// 	{
// 		// 1. Die Adresse des nächsten Elements retten,
//      // bevor wir das aktuelle löschen
// 		tmp = (*lst)->next;

// 		// 2. Den Inhalt des aktuellen Elements mit
// 		// der übergebenen Funktion freigeben
// 		del((*lst)->content);

// 		// 3. Den Speicherplatz des aktuellen Elements
//     // (Knotens) selbst freigeben
// 		free(*lst);

// 		// 4. Den Originalzeiger auf das gerettete, nächste Element verschieben
// 		*lst = tmp;
// 	}

// 	// Nach der Schleife ist *lst automatisch NULL. 
// 	// Der Originalzeiger aus dem Hauptprogramm zeigt nun also sicher auf NULL.
// }

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// // ---------------------------------------------------------
// // 1. Eigene Hilfsfunktion zum Löschen des Inhalts
// // ---------------------------------------------------------
// void del_content(void *content)
// {
//     // Da unser Inhalt in der main() mit strdup (also malloc) 
//     // erstellt wird, reicht hier ein einfaches free().
//     free(content);
//     printf(" -> Ein Listen-Inhalt wurde freigegeben!\n");
// }

// // ---------------------------------------------------------
// // 2. ft_lstclear Funktion
// // ---------------------------------------------------------
// void ft_lstclear(t_list **lst, void (*del)(void*))
// {
//     t_list *tmp;

//     if (!lst || !del)
//         return;
//     while (*lst)
//     {
//         tmp = (*lst)->next;
//         del((*lst)->content);
//         free(*lst);
//         *lst = tmp;
//     }
// }

// // ---------------------------------------------------------
// // 3. Das Hauptprogramm zum Testen
// // ---------------------------------------------------------
// int main(void)
// {
//     // Wir reservieren Speicher für 3 Knoten
//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));

//     // Wir weisen ihnen dynamischen Inhalt zu (strdup ruft intern malloc auf)
//     node1->content = strdup("Erstes Element");
//     node2->content = strdup("Zweites Element");
//     node3->content = strdup("Drittes Element");

//     // Wir verketten die Knoten
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     // Das ist unser Hauptzeiger, der auf den Anfang der Liste zeigt
//     t_list *mylist = node1;

//     printf("Vor dem Loeschen:\n");
//     printf("mylist zeigt auf die Adresse: %p\n\n", (void*)mylist);

//     printf("Starte ft_lstclear...\n");

//     // Wir rufen die Funktion auf. 
//     // Wichtig: &mylist (Adresse des Zeigers)
//     // und del_content (unsere Funktion)
//     ft_lstclear(&mylist, del_content);

//     printf("\nNach dem Loeschen:\n");

//     // Wenn alles richtig war, ist mylist jetzt NULL
//     if (mylist == NULL)
//         printf("Erfolg! mylist ist nun NULL. Es gibt keine Memory Leaks.\n");
//     else
//         printf("Fehler: mylist ist nicht NULL!\n");

//     return (0);
// }
