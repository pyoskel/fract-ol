/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:06:38 by pabartoc          #+#    #+#             */
/*   Updated: 2026/05/29 14:52:32 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// // Version 1
// // -------------------------------------------------------------
// // Unsere Hilfsfunktion "f", die wir auf jeden Knoten anwenden wollen
// // -------------------------------------------------------------
// void    print_content(void *content)
// {
//     // Wir wissen, dass unser content ein String ist,
//     // also casten wir ihn zu (char *)
//     printf("%s!!!\n", (char *)content);
// }

// // (Hier würden in deinem echten Programm noch ft_lstadd_back
// // und ft_lstlast stehen)
// // 
// // Wir simulieren den manuellen Aufbau kurz für dieses Beispiel:

// int main(void)
// {
//     // 1. Liste aufbauen
//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));

//     node1->content = strdup("Hallo");
//     node2->content = strdup("aus");
//     node3->content = strdup("der Liste");

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     t_list *mylist = node1;

//     printf("--- STARTE ft_lstiter ---\n");

//     // Wir übergeben unsere Liste (kein &, da
//     //                             kein Doppelzeiger erwartet wird)
//     // und unsere Hilfsfunktion print_content
//     ft_lstiter(mylist, print_content);

//     // Speicher aufräumen
//     free(node1->content); free(node1);
//     free(node2->content); free(node2);
//     free(node3->content); free(node3);

//     return (0);
// }

// -------------------------------------------------------------
// -------------------------------------------------------------

// // Version 2
// // -------------------------------------------------------------
// // Hilfsfunktion 1: Gibt den Inhalt einfach aus
// // -------------------------------------------------------------
// void    print_content(void *content)
// {
//     printf("- %s\n", (char *)content);
// }

// // -------------------------------------------------------------
// // Hilfsfunktion 2: Wandelt alle Kleinbuchstaben in Großbuchstaben um
// // -------------------------------------------------------------
// void    make_uppercase(void *content)
// {
//     char    *str;
//     int     i;

//     str = (char *)content; // Wir wissen, es ist ein String, also casten wir
//     if (!str)
//         return ;

//     i = 0;
//     while (str[i] != '\0')
//     {
//         // Wenn es ein Kleinbuchstabe ist (ASCII-Werte von 'a' bis 'z')
//         if (str[i] >= 'a' && str[i] <= 'z')
//         {
//             // In der ASCII-Tabelle liegen Großbuchstaben
//			   // genau 32 Stellen davor
//             str[i] = str[i] - 32;
//         }
//         i++;
//     }
// }

// // -------------------------------------------------------------
// // Das Hauptprogramm
// // -------------------------------------------------------------
// int main(void)
// {
//     // Wir bauen die Liste manuell auf
//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));

//     node1->content = strdup("das ist");
//     node2->content = strdup("echt coole");
//     node3->content = strdup("zeiger-magie");

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     t_list *mylist = node1;

//     // 1. Liste im Originalzustand ausdrucken
//     printf("--- VOR ft_lstiter ---\n");
//     ft_lstiter(mylist, print_content);

//     // 2. Wir jagen unsere uppercase-Funktion über die gesamte Liste!
//     ft_lstiter(mylist, make_uppercase);

//     // 3. Liste nach der Veränderung ausdrucken
//     printf("\n--- NACH ft_lstiter (make_uppercase) ---\n");
//     ft_lstiter(mylist, print_content);

//     // Speicher aufräumen
//     free(node1->content); free(node1);
//     free(node2->content); free(node2);
//     free(node3->content); free(node3);

//     return (0);
// }

// -------------------------------------------------------------
// with explanation
// -------------------------------------------------------------

// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	// Sicherheitsabfrage: Gibt es die Liste und die Funktion f?
// 	if (!lst || !f)
// 		return ;

// 	// Solange wir nicht am Ende der Liste angekommen sind
// 	while (lst)
// 	{
// 		// 1. Wende die Funktion f auf den Inhalt des aktuellen Knotens an
// 		f(lst->content);

// 		// 2. Gehe einen Knoten weiter
// 		lst = lst->next;
// 	}
// }