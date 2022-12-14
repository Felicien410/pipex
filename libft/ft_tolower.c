/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:26:29 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/16 13:46:33 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower( int character)
{
	if (character >= 65 && character <= 90)
		character += 32;
	return (character);
}
/*
int main()
{
	printf("%c", toupper('a'));
	printf("%c", toupper('A'));
	printf("%c", toupper('4'));

}*/
