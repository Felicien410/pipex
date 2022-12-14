/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:26:29 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/11 21:43:52 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	const char		*src2;

	dest2 = dest;
	src2 = src;
	src2 = (const char *) src;
	dest2 = (unsigned char *) dest;
	i = 0;
	if (!dest2 && !src2)
		return (0);
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
/*
int main() 
{
    memcpy(((void *)0), ((void *)0), 3);
  
}*/
