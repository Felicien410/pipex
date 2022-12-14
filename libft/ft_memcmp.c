/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:55:04 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/16 15:55:07 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (n)
	{
		n--;
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int main () {
   char *str1 = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
   char *str2 = "\xff\0\0\xaa\0\xde\x00MBS";
   size_t size = 9;
   int ret;

   ret = memcmp(str1, str2, size);

   printf("%d", ret);
   printf("\n");
   ret = ft_memcmp(str1, str2, size);

   printf("%d", ret);

   
   return(0);
}*/
