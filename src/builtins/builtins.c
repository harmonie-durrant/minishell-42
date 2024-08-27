/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:51:37 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 16:48:49 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_builtin(t_minishell *mini_data, char **args)
{
	int		ret;
	char	*pwd;
	int		i;
	char	*arg_formated;

	ret = 0;
	i = 0;
	while (args[i])
		i++;
	if (i > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
		mini_data->exit_code = 1;
		return (1);
	}
	if (args[1] == NULL)
		ret = change_to_home(mini_data);
	arg_formated = format_dollar(args[1], mini_data);
	if (!ft_strncmp(arg_formated, "-", 1))
	{
		pwd = get_env("PWD", mini_data->env);
		if (pwd != NULL)
			ret = change_to_previous(mini_data);
		if (ret == -1)
			ret = change_to_home(mini_data);
		free(pwd);
	}
	else
		ret = change_to_directory(arg_formated, mini_data);
	free(arg_formated);
	mini_data->exit_code = ret;
	return (ret);
}

int	pwd_builtin(t_minishell *mini_data, char **args)
{
	(void)args;
	ft_printf("%s\n", getcwd(NULL, 0));
	mini_data->exit_code = 0;
	return (0);
}

int	unset_builtin(t_minishell *mini_data, char **args)
{
	int	i;

	i = 1;
	if (!args[1])
		write(STDERR_FILENO, "unset: not enough arguments\n", 29);
	while (args[i])
	{
		unset_env(args[i], mini_data);
		i++;
	}
	mini_data->exit_code = 0;
	return (0);
}
