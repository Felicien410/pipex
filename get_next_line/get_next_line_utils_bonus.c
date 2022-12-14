/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:06:28 by fcatteau          #+#    #+#             */
/*   Updated: 2022/12/08 14:32:28 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	tab = (char *)malloc(len + 1);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			tab[j++] = s[i];
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

char	*ft_strchr( const char *string, int searchedChar )
{
	int	i;

	i = 0;
	while (string[i] != (char) searchedChar)
	{
		if (string[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)string + i);
}

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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*all;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	all = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!all)
		return (NULL);
	while (s1[i])
		all[j++] = s1[i++];
	i = 0;
	while (s2[i])
		all[j++] = s2[i++];
	all[j] = '\0';
	free(s1);
	return (all);
}
