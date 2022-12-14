/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:55:59 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/26 18:19:36 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);

size_t	ft_put_adresse(void *adresse);
size_t	ft_putchar(const char c);
size_t	ft_put_hexa(const unsigned int adresse, char c);
size_t	ft_putnbr(const unsigned int n);
size_t	ft_putnbr_base(int nbr, char *base);
size_t	ft_putstr(const char *s);
size_t	ft_strlen(const char *str);

#endif