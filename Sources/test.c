/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:04:23 by atouba            #+#    #+#             */
/*   Updated: 2022/05/21 22:33:02 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int main()
{
    // t_token *start;
    // char    *s = malloc(sizeof(char) * 6);
    // s = "hello";
    // start = ft_tokennew(s, NULL);
    // printf("%s\n", start->token);
    // printf("%s\n", ft_substr("hello", 0, 3));
    printf("%d\n", first_occ("abcd", 'c'));
}