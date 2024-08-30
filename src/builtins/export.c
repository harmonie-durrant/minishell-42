/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:53:36 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/29 15:17:27 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	export_arg_check(char *arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
	{
		if (!ft_isalpha(arg[i]) && arg[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

static void	export_err(t_minishell *mini_data)
{
	ft_putstr_fd("export: not a valid identifier\n", STDERR_FILENO);
	mini_data->exit_code = 1;
}

static int	export_with_args(char **args, t_minishell *mini_data, int i)
{
	int		ret;
	char	**str;
	char	*tmp;

	i = 1;
	while (args[i++])
	{
		str = ft_split(args[i - 1], '=');
		if (!str || !str[0] || export_arg_check(str[0]) == 1)
		{
			export_err(mini_data);
			free_2d(str);
			return (1);
		}
		tmp = get_env(str[0], mini_data->env);
		if (!str[1])
			ret = ft_export(str[0], tmp, 0, mini_data);
		else
			ret = ft_export(str[0], str[1], 0, mini_data);
		free(tmp);
		free_2d(str);
		if (ret == 1)
			return (1);
	}
	return (0);
}

int	export_builtin(t_minishell *mini_data, char **args)
{
	int		i;

	i = 0;
	if (!args[1])
	{
		while (mini_data->env[i])
			ft_printf("declare -x %s\n", mini_data->env[i++]);
		mini_data->exit_code = 0;
		return (0);
	}
	if (export_with_args(args, mini_data, i) == 1)
		return (1);
	mini_data->exit_code = 0;
	return (0);
}
