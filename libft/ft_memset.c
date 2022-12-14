/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:41:17 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/09 15:41:56 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = ptr;
	while (n > 0)
	{
		p[i] = x;
		i++;
		n--;
	}
	return (ptr);
}
/*
int main()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore memset(): %s\n", str);
  
    // Fill 8 characters starting from str[13] with '.'
    //memset(str + 13, '.', 8*sizeof(char));
    ft_memset(str + 13, '.', 8*sizeof(char));
	
  
    printf("After memset():  %s", str);
    return 0;
}*/
