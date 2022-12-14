/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:34:50 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/16 13:42:36 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr( const char *string, int searchedChar )
{
	int	i;

	i = ft_strlen (string);
	while (i > 0)
	{
		if ((char)string[i] == (char)searchedChar)
		{
			return ((char *)string + i);
		}
		i--;
	}
	if ((char)string[i] == (char)searchedChar)
		return ((char *)string + i);
	return (NULL);
}	
// int main () {
// 	char *src = "tripouille";
// 	char *d1 = strrchr(src, 't' +256);
// 	char *d2 = ft_strrchr(src, 't' +256);
// 	printf("%s", d1);
// 	printf("\n");
// 	printf("%s", d2);
// }
