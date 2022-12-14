/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:04:31 by fcatteau          #+#    #+#             */
/*   Updated: 2022/12/08 14:32:00 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*recup_the_total_row(int fd, char *buf, char *stack)
{
	int		total_letters;
	char	*tmp;

	total_letters = 1;
	while (total_letters != 0)
	{
		total_letters = read (fd, buf, BUFFER_SIZE);
		if (total_letters == -1)
		{
			free(stack);
			stack = NULL;
			return (NULL);
		}
		if (total_letters == 0)
			break ;
		buf[total_letters] = '\0';
		if (!stack)
			stack = ft_strdup ("");
		tmp = stack;
		stack = ft_strjoin_gnl (tmp, buf);
		tmp = NULL;
		if (ft_strchr (stack, '\n'))
			return (stack);
	}
	return (stack);
}

char	*get_left(char *all_line)
{
	size_t	i;
	char	*final;

	i = 0;
	while (all_line[i] && all_line[i] != '\n')
		i++;
	final = (char *)malloc (sizeof (char) * i + 2);
	if (!final)
		return (NULL);
	i = 0;
	while (all_line[i] && all_line[i] != '\n')
	{
		final[i] = all_line[i];
		i++;
	}
	if (all_line[i] == '\n')
		final[i] = '\n';
	else
		final[i] = '\0';
	final[i + 1] = '\0';
	return (final);
}

char	*get_right(char *all_line)
{
	size_t	i;
	char	*stack;

	i = 0;
	while (all_line[i] && all_line[i] != '\n')
		i++;
	if (all_line[i] == '\0' || all_line[1] == '\0')
		return (0);
	stack = ft_substr (all_line, i + 1, ft_strlen(all_line + i));
	if (*stack == '\0')
	{
		free(stack);
		stack = NULL;
	}
	return (stack);
}

char	*get_next_line(int fd)
{
	char		*all_line;
	char		*buf;
	static char	*stack;
	char		*left;

	all_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{	
		free (stack);
		stack = NULL;
		return (0);
	}
	buf = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	all_line = recup_the_total_row (fd, buf, stack);
	free (buf);
	buf = NULL;
	if (!all_line)
		return (NULL);
	left = get_left (all_line);
	stack = get_right (all_line);
	free (all_line);
	all_line = NULL;
	return (left);
}
