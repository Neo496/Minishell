/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:53:21 by atouba            #+#    #+#             */
/*   Updated: 2022/05/17 17:25:08 by atouba           ###   ########.fr       */
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

int	main()
{
	int		i;
	t_line	line;
	char	*rl;

	i = 0;
	signal(SIGINT, &handle_control);
	while (1)
	{
		rl = readline("\033[0;33mMinishell $>  \033[0m");
		if (!rl)
			exit(0);
		line.commands = ft_split(rl, ' ');
		line.pipes = counter(rl, '|');
		line.semicolons = counter(rl, ';');
		while (line.commands[i])
			printf("%s\n", line.commands[i++]);
		i = 0;
		printf("semicolon counter: %d\npipe counter: %d\n", counter(rl, ';'), counter(rl, '|'));
	}
}