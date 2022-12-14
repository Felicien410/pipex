/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:53:15 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/15 14:48:38 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*ptr;

	if (f == NULL || lst == NULL)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		final = ft_lstnew(f(lst->content));
		if (!final)
		{
			del(final);
			return (NULL);
		}
		ft_lstadd_back (&ptr, final);
		final = final->next;
		lst = lst->next;
	}
	return (ptr);
}
