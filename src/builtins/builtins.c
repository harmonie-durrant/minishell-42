/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:51:37 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 11:53:58 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_builtin(t_minishell *mini_data, char **args)
{
	int		i;
	char	*tmp;
	int		flag_n;

	flag_n = 0;
	i = 1;
	if (args[1] && !ft_strncmp(args[1], "-n", 2))
	{
		flag_n = 1;
		i++;
	}
	while (args[i])
	{
		tmp = remove_double_quotes(args[i]);
		ft_printf("%s", tmp);
		free(tmp);
		if (args[i + 1])
			ft_printf(" ");
		i++;
	}
	if (!flag_n)
		ft_printf("\n");
	mini_data->exit_code = 0;
	return (0);
}

int	cd_builtin(t_minishell *mini_data, char **args)
{
	int		ret;
	char	*pwd;

	ret = 0;
	if (args[1] == NULL)
		ret = change_to_home(mini_data);
	else if (args[2])
	{
		write(STDERR_FILENO, "too many arguments\n", 20);
		return (1);
	}
	else if (!ft_strncmp(args[1], "-", 1))
	{
		pwd = get_env("PWD", mini_data->env);
		if (pwd != NULL)
			ret = change_to_previous(mini_data);
		if (ret == -1)
			ret = change_to_home(mini_data);
		free(pwd);
	}
	else
		ret = change_to_directory(args[1], mini_data);
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
