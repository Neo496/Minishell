/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:56:59 by atouba            #+#    #+#             */
/*   Updated: 2022/05/20 14:00:32 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_add_token_front(t_token **lst, t_token *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}