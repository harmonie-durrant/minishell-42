/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minishell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:21:11 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 16:40:25 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**make_env(char const *envp[])
{
	int		i;
	char	**env;

	i = 0;
	while (envp[i])
		i++;
	env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!env)
		exit(1);
	i = 0;
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		if (!env[i])
			exit(1);
		i++;
	}
	env[i] = NULL;
	return (env);
}

void	ft_lstfree(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_minishell(t_minishell *mini_data)
{
	if (!mini_data)
		return ;
	if (mini_data->history)
		ft_lstclear(&mini_data->history, &ft_lstfree);
	if (mini_data->tree)
		destroy_tree(mini_data->tree);
	if (mini_data->env)
		free_2d(mini_data->env);
	free(mini_data);
}

t_minishell	*init_minishell(char const *envp[])
{
	t_minishell	*mini_data;

	mini_data = (t_minishell *)malloc(sizeof(t_minishell));
	if (!mini_data)
		exit(1);
	mini_data->env = make_env(envp);
	mini_data->exit_code = 0;
	mini_data->history = NULL;
	mini_data->tree = NULL;
	return (mini_data);
}