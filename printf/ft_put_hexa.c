/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:58:51 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/26 18:10:58 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

size_t	ft_put_hexa(const unsigned int adresse, char c)
{
	if (adresse / 16)
	{
		return (ft_put_hexa (adresse / 16, c) + ft_put_hexa (adresse % 16, c));
	}
	else if ((adresse / 10) == 0)
	{
		return (ft_putchar(adresse + '0'));
	}
	else
		return (ft_putchar(adresse - 10 + c));
	return (1);
}
