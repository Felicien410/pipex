/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:57:35 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/16 15:57:37 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *string)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(string)+1);
	if (!dup)
	{
		return (NULL);
	}
	while (string[i])
	{
		dup[i] = string[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
