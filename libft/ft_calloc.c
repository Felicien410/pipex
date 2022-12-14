/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:33:46 by feliciencat       #+#    #+#             */
/*   Updated: 2022/11/16 12:12:37 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ad;
	size_t	lenght;

	if ((unsigned int)nitems * (unsigned int)size == 0 && nitems && size)
	{
		return (NULL);
	}
	if (nitems != 0 && size >= SIZE_MAX / nitems)
		return (NULL);
	lenght = nitems * size;
	ad = malloc(sizeof(void) * lenght);
	if (!ad)
		return (NULL);
	ft_bzero (ad, lenght);
	return (ad);
}
