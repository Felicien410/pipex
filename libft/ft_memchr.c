/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:18:16 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/12 18:37:18 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size )
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((char *)memoryBlock)[i] == (char)searchedChar)
		{
			return ((void *)memoryBlock + i);
		}
		i++;
	}
	return (0);
}
/*
int main () {
   char *str = "boulot";
   int ch = "o";
   char *ret;

   ret = memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);

   ret = ft_memchr(str, ch, strlen(str));
   printf("\n");

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}
*/
