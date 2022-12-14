/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:32:15 by feliciencat       #+#    #+#             */
/*   Updated: 2022/11/16 12:20:23 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*all;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	all = malloc(ft_strlen(s1) + ft_strlen(s2)+1);
	if (!all)
		return (NULL);
	while (s1[i])
		all[j++] = s1[i++];
	i = 0;
	while (s2[i])
		all[j++] = s2[i++];
	all[j] = '\0';
	return (all);
}
/*
int main()
{
	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";
	char *res = ft_strjoin(ft_strjoin(s1, s2), s3);
    printf("%s", res);
}*/
