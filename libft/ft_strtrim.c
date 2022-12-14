/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:13:27 by feliciencat       #+#    #+#             */
/*   Updated: 2022/11/15 20:58:39 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	isch(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;
	int		i;
	char	*dup;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (!s1 && !set)
		return (NULL);
	while (s1[start] && isch (s1[start], (char *)set) == 1)
		start++;
	while (end > start && isch (s1 [end - 1], (char *)set) == 1)
		end--;
	i = 0;
	dup = malloc(sizeof(*s1) * (end - start + 1));
	if (!dup)
		return (NULL);
	while (start < end)
		dup[i++] = s1[start++];
	dup[i] = '\0';
	return (dup);
}
/*
int main()
{
    char *s1 = "  \t \t \n   \n\n\n\t";
    char *s2 = "";
    printf("%s", ft_strtrim(s1,s2));
}*/
