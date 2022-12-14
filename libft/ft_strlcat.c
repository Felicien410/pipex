/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:26:29 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/16 12:22:50 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s1;
	size_t	s2;

	if ((!source || !destination) && n == 0)
		return (0);
	if (n <= ft_strlen(destination))
	{
		return (n + ft_strlen(source));
	}
	i = 0;
	s1 = ft_strlen(destination);
	s2 = ft_strlen(source);
	j = s1;
	if (s1 < n - 1 && n > 0)
	{	
		while (source[i] && s1 + i < n - 1)
			destination[j++] = source[i++];
	destination[j] = '\0';
	}
	if (s1 >= n)
		s1 = n;
	return (s1 + s2);
}
// int main () {
// 	char b[0xF] = "nyan !";
// 	printf("%zu\n",strlcat(((void *)0), b, 0));
// 	printf("%zu\n",ft_strlcat(((void *)0), b, 0));
//     return(0);
// }
