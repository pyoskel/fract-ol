/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 05:47:49 by pabartoc          #+#    #+#             */
/*   Updated: 2025/08/18 06:32:50 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (!dst && !src)
		return (dst);
	dst_ptr = (unsigned char *) dst;
	src_ptr = (const unsigned char *) src;
	while (n > 0)
	{
		*dst_ptr++ = *src_ptr++;
		n--;
	}
	return (dst);
}

// === eigene Main Funktion ===
// int main(void)
// {
//     char    str[] = "Guten Morgen Wie geht's?";
//     char    dest[100];
//     int     n = 12;
//     char    *result; // Eine Variable für das Ergebnis

//     result = (char *)ft_memcpy(dest, str, n);
//     printf("%s\n", result);
//     return (0);
// }

// 	// === === Main aus dem Netz === ===
// int	main(void)
// {
// 	// === TEST 1: String-Kopie (Dein Anwendungsfall) ===
// 	printf("--- Test 1: String-Kopie ---\n");
// 	char	src_str[] = "Guten Morgen, Wie geht's?"; // Quelle
// 	char	dest_ft[100]; // Ziel für deine Funktion
// 	char	dest_orig[100]; // Ziel für die Original-Funktion
// 	size_t n = 14;

// 	// Test mit deiner Funktion
// 	ft_memcpy(dest_ft, src_str, n);
// 	dest_ft[n] = '\0'; // WICHTIG: Manuell Null-terminieren für printf!

// 	// Test mit der echten C-Funktion
// 	memcpy(dest_orig, src_str, n);
// 	dest_orig[n] = '\0'; // Auch hier Null-terminieren

	// printf("Original memcpy: \"%s\"\n", dest_orig);
// 	printf("Deine ft_memcpy:   \"%s\"\n\n", dest_ft);

// 	// === TEST 2: Integer-Array kopieren ===
// 	printf("--- Test 2: Integer-Array ---\n");
// 	int	src_int[] = {100, 200, -300, 400, 500};
// 	int	dest_int[5];
// 	size_t num_bytes = sizeof(src_int); // sizeof() berechnet die Größe in Bytes

// 	printf("Original-Array: {%d, %d, %d, %d, %d}\n",
// 		src_int[0], src_int[1], src_int[2], src_int[3], src_int[4]);

// 	// Kopieren mit deiner Funktion
// 	ft_memcpy(dest_int, src_int, num_bytes);

// 	printf("Kopiertes Array: {%d, %d, %d, %d, %d}\n",
// 		dest_int[0], dest_int[1], dest_int[2], dest_int[3], dest_int[4]);

// 	return (0);
// }
