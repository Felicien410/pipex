/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:57:58 by fcatteau          #+#    #+#             */
/*   Updated: 2022/12/01 18:07:04 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static	size_t	printable(const char *str, size_t *i, va_list ap)
{
	*i = *i + 1;
	if (*(str + 1) == 's')
		return (ft_putstr(va_arg (ap, char *)));
	else if (*(str + 1) == 'c')
		return (ft_putchar(va_arg (ap, int)));
	else if (*(str + 1) == 'p')
		return (ft_put_adresse (va_arg (ap, void *)));
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		return (ft_putnbr_base (va_arg(ap, int), "0123456789"));
	else if (*(str + 1) == 'u')
		return (ft_putnbr (va_arg(ap, int)));
	else if (*(str + 1) == 'x')
		return (ft_put_hexa (va_arg(ap, int), 'a'));
	else if (*(str + 1) == 'X')
		return (ft_put_hexa (va_arg(ap, int), 'A'));
	else if (*(str + 1) == '%')
		return (ft_putchar('%'));
	else
	{
		*i -= 1;
		return (0);
	}
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	ap;
	int		len;

	i = 0;
	len = 0;
	va_start (ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += (printable (str + i, &i, ap));
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end (ap);
	return (len);
}
