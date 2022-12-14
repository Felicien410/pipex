/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:56:56 by fcatteau          #+#    #+#             */
/*   Updated: 2022/12/01 18:07:42 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

size_t	ft_putnbr_base(int nb, char *base)
{
	int			len_base;
	long long	tab_nub[100];
	int			i;
	size_t		len;
	long long	nbr;

	nbr = (long long) nb;
	i = 0;
	len = 0;
	len_base = ft_strlen(base);
	if (nbr == 0 || nbr < -9223372036854775807)
		return (len += ft_putchar('0'));
	if (nbr < 0)
	{
		nbr = -nbr;
		len += ft_putchar('-');
	}
	while (nbr > 0)
	{
		tab_nub[i++] = nbr % len_base;
		nbr = nbr / len_base;
	}
	while (--i >= 0)
		len += ft_putchar(base[tab_nub[i]]);
	return (len);
}
