/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:13:37 by atouba            #+#    #+#             */
/*   Updated: 2022/05/21 20:07:52 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!*lst)
		*lst = new;
	else
	{
		curr = ft_lstlast(*lst);
		curr->next = new;
	}
}

void	ft_push_token_back(t_token **lst, t_token *new)
{
	t_token	*curr;

	if (!*lst)
		*lst = new;
	else
	{
		curr = ft_token_last(*lst);
		curr->next = new;
		new->prev = curr;
	}
}