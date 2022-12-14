/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:34:50 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/16 15:57:47 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr( const char *string, int searchedChar )
{
	int	i;

	i = 0;
	while (string[i] != (char) searchedChar)
	{
		if (string[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)string + i);
}
/*
int main () {
	char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	char *d1 = strchr(src, '\0');
	char *d2 = ft_strchr(src, '\0');

	if (d1 == d2)
	{
		printf("OUIII");
		return 0;
	}
	else
	{
	printf("NONnNN");
	printf("%s\nd1", d1);
	printf("%s\nd2", d2);
	return 1;
	}
}*/
