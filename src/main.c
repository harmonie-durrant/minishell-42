/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:49:31 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 15:56:52 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_user_input(void)
{
	char	*line;

	line = readline("$ ");
	return (line);
}

static int	minishell(t_minishell *mini_data)
{
	char	*input;

	input = get_user_input();
	if (!input)
	{
		ft_printf("exit\n");
		return (0);
	}
	if (input[0] == '\0')
	{
		free(input);
		return (minishell(mini_data));
	}
	parse_input(input, mini_data);
	if (mini_data->tree)
	{
		execute_tree(mini_data, mini_data->tree);
		destroy_tree(mini_data->tree);
	}
	free(input);
	return (minishell(mini_data));
}

void	mini_exit(t_minishell *mini_data)
{
	int	status;

	status = mini_data->exit_code;
	free_minishell(mini_data);
	exit(status);
}

void	sig_handler(int signo)
{
	if (signo == SIGQUIT)
		return ;
	if (signo == SIGINT)
		ft_putstr_fd("\n$ ", 1);
}

int	main(int argc, char const *argv[], char const *envp[])
{
	t_minishell	*mini_data;
	int 		ret;
	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("minishell: too many arguments\n", 2);
		return (1);
	}
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		return (1);
	else if (signal(SIGQUIT, sig_handler) == SIG_ERR)
		return (1);
	mini_data = init_minishell(envp);
	ret = minishell(mini_data);
	free_minishell(mini_data);
	return (ret);
}
