/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatteau <fcatteau@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:21:06 by fcatteau          #+#    #+#             */
/*   Updated: 2022/11/16 15:54:16 by fcatteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_unit(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del (lst->content);
		free (lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	tmp = NULL;
	if (!del || !lst || !(*lst))
	{
		return ;
	}
	while (*lst && lst)
	{	
		tmp = (*lst)->next;
		del_unit(*lst, del);
		*lst = tmp;
	}
}
