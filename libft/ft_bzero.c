/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:38:00 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/08 21:41:02 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*string;
	size_t	i;

	string = s;
	i = 0;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}	
}
/*
int main(void)
  {
    char buffer[80] = "bonjour";

    printf("%s",bzero( buffer, 0));
	printf("%s",ft_bzero( buffer,0));
    return EXIT_SUCCESS;
  }*/
