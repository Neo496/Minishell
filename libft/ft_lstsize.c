/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:33:09 by atouba            #+#    #+#             */
/*   Updated: 2022/05/20 13:57:32 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = lst;
	while (curr != 0)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int	ft_tokens_size(t_token *lst)
{
	t_token	*curr;
	int		i;

	i = 0;
	curr = lst;
	while (curr != 0)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}