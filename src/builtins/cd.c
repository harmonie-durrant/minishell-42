/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:55:41 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/28 09:12:55 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_check_args(t_minishell *mini_data, char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
		mini_data->exit_code = 1;
		return (1);
	}
	return (0);
}

int	check_change_to_home(t_minishell *mini_data, char **args)
{
	int	ret;

	ret = -1;
	if (args[1] == NULL)
		ret = change_to_home(mini_data);
	if (ret == 2)
		ft_putstr_fd("cd: HOME not set\n", 2);
	if (ret == 1 || ret == 2)
	{
		mini_data->exit_code = 1;
		ret = 1;
	}
	return (ret);
}

int	cd_builtin(t_minishell *mini_data, char **args)
{
	int		ret;
	char	*pwd;
	char	*arg_formated;

	ret = check_change_to_home(mini_data, args);
	if (ret == 1 || ret == 0)
		return (ret);
	if (cd_check_args(mini_data, args) == 1)
		return (1);
	arg_formated = format_dollar(args[1], mini_data);
	if (!ft_strncmp(arg_formated, "-", 1))
	{
		pwd = get_env("OLDPWD", mini_data->env);
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
