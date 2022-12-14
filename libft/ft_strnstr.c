/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:29:08 by feliciencat       #+#    #+#             */
/*   Updated: 2022/11/16 12:28:12 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && size == 0)
		return (NULL);
	if (needle[0] == '\0' || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] && (i < size))
	{
		j = 0;
		while (haystack[i + j] == needle [j] && i + j < size)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}		
	return (NULL);
}
// int main()
// {
//     char largestring[30] = "abcd";
//     char smallstring[10] = "abcd";
//     char * empty = (char *)"";

//     printf("%s", strnstr(empty, "coucou", -1));
//     printf("\n");
//     printf("%s", ft_strnstr(empty, "coucou", -1));
// }
