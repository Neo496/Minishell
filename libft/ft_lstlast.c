/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:03:51 by atouba            #+#    #+#             */
/*   Updated: 2022/05/20 17:19:33 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (0);
	curr = lst;
	while (curr->next != 0)
		curr = curr->next;
	return (curr);
}

t_token	*ft_token_first(t_token *lst)
{
	t_token	*curr;

	if (!lst)
		return (0);
	curr = lst;
	while (curr->prev != 0)
		curr = curr->prev;
	return (curr);
}

t_token	*ft_token_last(t_token *lst)
{
	t_token	*curr;

	if (!lst)
		return (0);
	curr = lst;
	while (curr->next != 0)
		curr = curr->next;
	return (curr);
}
