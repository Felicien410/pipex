/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adresse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:08:39 by fcatteau          #+#    #+#             */
/*   Updated: 2022/12/02 14:56:03 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	size_t	put_adress(const unsigned long adresse)
{
	if (adresse / 16)
		return (put_adress (adresse / 16) + put_adress (adresse % 16));
	else if ((adresse / 10) == 0)
		return (ft_putchar(adresse + '0'));
	else
		return (ft_putchar(adresse - 10 + 'a'));
	return (1);
}

size_t	ft_put_adresse(void *adresse)
{
	if (!adresse)
		return (ft_putstr("0x0"));
	ft_putstr("0x");
	return (2 + put_adress((unsigned long) adresse));
}
