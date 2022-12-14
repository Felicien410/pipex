/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:53:50 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/16 12:26:39 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char	*first, const char	*seconde, size_t length)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)first;
	s2 = (unsigned char *)seconde;
	i = 0;
	if (length == 0)
		return (0);
	while ((s1[i] || s2[i]) && i <= length - 1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char s1[] = "aaa";
	char s2[] = "a";
	printf("%d\n", ft_strncmp(s1,s2,3));
	printf("%d\n",strncmp(s1,s2,3));

}
*/
