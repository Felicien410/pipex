/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:02:34 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/16 15:57:13 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*freearray(char **s, int i)
{
	while (i-- > 0)
	{
		free(s[i]);
	}
	free(s);
	return (NULL);
}

static size_t	len_split(const char *s, char c)
{
	unsigned int	i;
	size_t			lenght;

	i = 0;
	lenght = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i++])
		lenght++;
	return (lenght);
}

static size_t	count_words(const char *str, char c)
{
	unsigned int	i;
	size_t			t;

	i = 0;
	t = 0;
	while (str[i])
	{
		if (str[i] != c)
			t++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (t);
}

static int	count(char const *s, char c, int t)
{
	while (s[t] == c)
		t++;
	return (t);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	t;
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = -1;
	t = 0;
	while (++i < count_words(s, c))
	{
		tab[i] = (char *) malloc(sizeof(char) * (len_split(s + t, c) + 1));
		if (!tab[i])
			return (freearray(tab, i));
		j = 0;
		t = count(s, c, t);
		while (s[t] != c && s[t])
			tab[i][j++] = s[t++];
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
// int main()
// {
//     char **tab ;
//     char c = 'j';

//     tab = ft_split("", 'z');

//     int i = 0;

//     while(tab[i])
//     {
//         printf("%s\n", tab[i]);
//         i++;
//     }
// }
