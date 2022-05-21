/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:54:34 by atouba            #+#    #+#             */
/*   Updated: 2022/05/21 21:36:21 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "libft/libft.h"

//#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <locale.h>                 //
#include <sys/types.h>              //
#include <sys/select.h>             //
#include <string.h>                 //
#include <sys/types.h>              //
# include <sys/file.h>              //
#include <fcntl.h>                  //
#include <errno.h>                  //

/*----------------------------------------------------------------*/

typedef struct s_line
{
	char	**commands;
	int		semicolons;
	int		pipes;
}				t_line;


int	first_occ(char *s, char c);

// typedef struct node
// {
// 	struct node	*left;
// 	struct node	*right;
// 	struct node	*parent;
// 	char	node_type; // ';' or '&' or '|' or 'e' or ''
// 	char	**block; // != NUll if this node_type == 'e' 
// }  				t_node;

// typedef struct tokens
// {
// 	char		*token;
// 	struct tokens	*prev;
// 	struct tokens	*next;
// }			t_token;

#endif