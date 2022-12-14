/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:27:53 by fcatteau          #+#    #+#             */
/*   Updated: 2022/12/01 18:06:34 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

size_t	ft_putnbr(const unsigned int n)
{
	if (n / 10)
		return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
	else
		return (ft_putchar(n + '0'));
}
