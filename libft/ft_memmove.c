/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:18:31 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/09 11:35:23 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len )
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (d == s)
		return (dst);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
/*
int main()
{
    char str1[] = "123456789"; // Array of size 100
    char str2[] = "123"; // Array of size 5
    puts("str1 before memmove ");
    puts(str1);
 
    memmove(str1, str2, sizeof(str2));
    puts("\nstr1 after memmove ");
    puts(str1);
	printf("----------------------\n");
    char strv1[] = "123456789"; // Array of size 100
    char strv2[] = "123"; // Array of size 5
    puts("str1 before mcopy ");
    puts(strv1);

    memcpy(strv1, strv2, sizeof(strv2));
    puts("\nstr1 after mcopy ");
    puts(strv1);
  
    return 0;
}
*/
