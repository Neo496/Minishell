/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:53:21 by atouba            #+#    #+#             */
/*   Updated: 2022/05/21 22:42:36 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	handle_control(int sig)
{
		write(1, "\n\033[0;33mMinishell $>  \033[0m", 27);
}

int	counter(char *line, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (line[i])
	{
		if (line[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

void	display_list(t_token *token, char *option)
{
	t_token	*curr;
	if (!strcmp(option, "start"))
	{
		curr = token;
		while (curr)
		{
			printf("%s\n", curr->token);
			curr = curr->next;
		}
	}
	else if (!strcmp(option, "end"))
	{
		curr = token;
		while (curr)
		{
			printf("%s\n", curr->token);
			curr = curr->prev;
		}
	}
}

int	check_quotations(char *s)
{
	if (counter(s, '"') % 2 || counter(s, '\'') % 2)
	{
		printf("Error: quotations");
		exit(1);
	}
	return (1);
}

t_token	*split_str_to_tokens(char *s, char c)
{
	t_token	*start_new_lst;
	int		i;
	int		begin;
	int		len;
	char	*sp;

	i = 0;
	start_new_lst = 0;
	begin = 0;
	sp = malloc(sizeof(char) * 2);
	while (s[i] && i < ft_strlen((const char *)s))
	{
		// begin = i;
		len = first_occ(s + i, c);
		ft_push_token_back(&start_new_lst, ft_tokennew(ft_substr(s, i, len), ft_token_last(start_new_lst)));
		if (s[len] == c)
		{
			sp[0] = c;
			sp[1] = '\0';
			ft_push_token_back(&start_new_lst, ft_tokennew(sp, ft_token_last(start_new_lst)));
			// free(sp);
			// sp = malloc(sizeof(char) * 2);  //  ***
		}
		// printf("x");j
		i += len + 1;
	}
	free(sp);
	return (start_new_lst);
}

// append_tokens : 	when cml_to_tokens push back each string (like ls or pwd from the command line, it's all good
//					but when it encounters a string like ls;pwd, we have to retrieve each token in a node, so we split
//					ls;pwd to ls ; pwd, each one in a node, then we append the last of the original list to the first of 
//					ls ; pwd list
void	append_tokens(char *s, t_token *start)
{
	t_token	*last_of_start;
	t_token	*to_append;

	// last_of_start = 0;
	// to_append = 0;
	// check_quotations(s);
	if (counter(s, ';'))
	{
		last_of_start = ft_token_last(start);
		// printf("A\n");
		to_append = split_str_to_tokens(s, ';');
		// printf("B\n");
		last_of_start->next = to_append;
		// printf("C\n");
		to_append->prev = last_of_start;
		// printf("D\n");
	}
}

t_token	*cml_to_tokens(char *cml)
{
	char	**tokens;
	int		i;
	t_token	*start;

	tokens = ft_split(cml, ' ');
	i = 0;
	start = 0;
	while (tokens[i])
	{
		if (counter(tokens[i], ';'))    // for example and as a start
			append_tokens(tokens[i], start);  //later we have to add an extra arg: char c like the one above, to be dynamic
		else
			ft_push_token_back(&start, ft_tokennew(tokens[i], ft_token_last(start)));
		i++;
	}
	return (start);
}

int	main()
{
	int		i;
	t_line	line;
	char	*rl;
	t_token	*start;

	i = 0;
	signal(SIGINT, &handle_control);
	rl = readline("\033[0;33mMinishell $>  \033[0m");
	while (rl)
	{
		start = cml_to_tokens(rl);
		display_list(start, "start");
		free(rl);
		rl = readline("\033[0;33mMinishell $>  \033[0m");
	}
	
	// t_token *start;
    // char    *s = malloc(sizeof(char) * 6);
    // s = "start";
    // start = ft_tokennew(s, NULL);
    // printf("%s\n", start->token);
	
	// while (i < 5)
	// {
	// 	ft_add_token_front(&start, ft_tokennew("hello", ft_token_last(start)));
	// 	// printf("X");
	// 	i++;
	// }
	
	// free(rl);
	// system("leaks minishell");
}