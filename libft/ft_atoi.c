/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:41:04 by feliciencat       #+#    #+#             */
/*   Updated: 2022/11/12 16:35:46 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
	{	
		i++;
	}
	if (str[i] != '\0' && str[i] == '-')
	{
		neg *= -1;
		i ++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit (str[i]) == 1)
	{
		result = result * 10 + str[i] - '0';
		i ++;
	}
	return (result * neg);
}
/*
int main()
{
    printf("%d\n", atoi("    42"));
    printf("%d\n", atoi("fdsfv"));
    printf("%d\n", atoi("qqq42"));
    printf("%d\n", atoi("\0"));
    printf("%d\n", atoi("\042"));
    printf("%d\n", atoi("\n42"));
    printf("%d\n", atoi(""));
    printf("\n");

    printf("%d\n", ft_atoi("    42"));
    printf("%d\n", ft_atoi("fdsfv"));
    printf("%d\n", ft_atoi("qqq42"));
    printf("%d\n", ft_atoi("\0"));
    printf("%d\n", ft_atoi("\042"));
    printf("%d\n", ft_atoi("\n42"));
    printf("%d\n", ft_atoi(""));   
}*/
