/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:49:45 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/16 12:25:14 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tab;

	if (!s)
		return (NULL);
	tab = (char *)malloc(ft_strlen(s) + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tab[i] = f (i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
/*
char my_func(unsigned int i, char str)
{
	printf("My inner function: index = %d and %c\n", i, str);
	return str - 32;
}

int main()
 {
 	char str[10] = "hello.";
 	printf("The result is %s\n", str);
 	char *result = ft_strmapi(str, my_func);
 	printf("The result is %s\n", result);
 	return 0;
 }
*/
