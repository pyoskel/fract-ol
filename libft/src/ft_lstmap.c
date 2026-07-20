/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:07:08 by pabartoc          #+#    #+#             */
/*   Updated: 2026/05/28 19:53:20 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*mapped_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		mapped_content = f(lst->content);
		new_node = ft_lstnew(mapped_content);
		if (!new_node)
		{
			del(mapped_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// // --- DEINE WERKZEUGKISTE (Die bereits bekannten Funktionen) ---
// t_list  *ft_lstlast(t_list *lst)
// {
//     if (!lst) return (NULL);
//     while (lst->next) lst = lst->next;
//     return (lst);
// }

// void    ft_lstadd_back(t_list **lst, t_list *new)
// {
//     if (!lst || !new)
// 		return ;
//     if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
//     ft_lstlast(*lst)->next = new;
// }

// void    ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list *tmp;
// 	if (!lst || !del)
// 		return;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		del((*lst)->content);
// 		free(*lst);
// 		*lst = tmp;
// 	}
// }

// t_list  *ft_lstnew(void *content)
// {
// 	t_list *node = malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->content = content;
// 	node->next = NULL;
// 	return (node);
// }

// // --- DER ENDBOSS ---
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_list;     // Der Hauptzeiger für unsere brandneue Liste
// 	t_list	*new_node;     // Ein temporärer Knoten für das Fließband
// 	void	*mapped_content; // Der neue, veränderte Inhalt

// 	if (!lst || !f || !del)
// 		return (NULL);

// 	new_list = NULL; // WICHTIG: Die neue Liste startet leer!

// 	while (lst) // Wandere durch die ALTE Liste
// 	{
// 		// 1. Erschaffe den neuen Inhalt mit der Funktion 'f'
// 		mapped_content = f(lst->content);

// 		// 2. Erstelle einen neuen Knoten mit diesem neuen Inhalt
// 		new_node = ft_lstnew(mapped_content);

// 		// 3. DER NOTFALL-PLAN (Wenn malloc in ft_lstnew fehlschlägt)
// 		if (!new_node)
// 		{
// 			del(mapped_content); // Lösche den gerade erstellten Inhalt
// 			// Vernichte die gesamte bisher gebaute neue Liste
//			ft_lstclear(&new_list, del);
// 			return (NULL); // Brich den Vorgang ab
// 		}

// 		// 4. Hänge den neuen Knoten sicher an das Ende unserer NEUEN Liste an
// 		ft_lstadd_back(&new_list, new_node);

// 		// 5. Gehe in der alten Liste einen Schritt weiter
// 		lst = lst->next;
// 	}
// 	return (new_list); // Gib die fertige, brandneue Liste zurück
// }

// // --- UNSERE SPEZIELLEN HILFSFUNKTIONEN FÜR DEN TEST ---
// void    del_content(void *content)
// {
// 	free(content);
// }

// // Diese Funktion baut einen komplett neuen String und gibt ihn zurück
// void    *append_copy_text(void *content)
// {
// 	char *old_str = (char *)content;
//	// Platz für Original + " - KOPIE"
// 	char *new_str = malloc(strlen(old_str) + 10);
// 	if (!new_str)
// 		return (NULL);

// 	strcpy(new_str, old_str);
// 	strcat(new_str, " - KOPIE");
// 	return (new_str);
// }

// void    print_list(t_list *lst, char *name)
// {
// 	printf("Liste '%s':\n", name);
// 	while (lst)
// 	{
// 		printf("  -> %s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("\n");
// }

// // --- DAS HAUPTPROGRAMM ---
// int main(void)
// {
// 	// 1. Wir bauen die ORIGINAL-Liste
// 	t_list *original = ft_lstnew(strdup("Apfel"));
// 	ft_lstadd_back(&original, ft_lstnew(strdup("Banane")));
// 	ft_lstadd_back(&original, ft_lstnew(strdup("Kirsche")));

// 	// 2. Original ausdrucken
// 	printf("VOR DEM MAPPING:\n");
// 	print_list(original, "Original");

// 	// 3. WIR ERSCHAFFEN DIE NEUE LISTE MIT ft_lstmap!
// 	t_list *neue_liste = ft_lstmap(original, append_copy_text, del_content);

// 	// 4. Beide Listen ausdrucken, um zu beweisen, dass sie unabhängig sind
// 	printf("NACH DEM MAPPING:\n");
// 	print_list(original, "Original (unberuehrt)");
// 	print_list(neue_liste, "Neue Liste");

// 	// 5. Speicher für BEIDE Listen komplett aufräumen
// 	ft_lstclear(&original, del_content);
// 	ft_lstclear(&neue_liste, del_content);

// 	return (0);
// }