/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:47:30 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/12 18:34:35 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	count_digits(long n)
{
	size_t	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		res ++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		res ++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	nbdigits;
	long	num;
	int		neg;
	char	*res;

	num = (long) n;
	nbdigits = count_digits (num);
	res = (char *)malloc (sizeof (char) * (nbdigits + 1));
	if (!res)
		return (NULL);
	res[nbdigits] = '\0';
	neg = 0;
	if (num < 0)
	{
		num *= -1;
		neg = 1;
	}
	while (nbdigits-- > 0)
	{
		res[nbdigits] = (num % 10) + 48;
		num /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
/*
int main()
{
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-623));
	printf("%s\n", ft_itoa(156));
	printf("%s\n", ft_itoa(-020));
}*/
