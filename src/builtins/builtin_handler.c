/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:39:21 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 13:37:11 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_builtin(t_minishell *mini_data, char **args)
{
	int		i;
	char	**tmp;

	if (args[1] != NULL)
	{
		ft_printf("env: too many args.\n");
		return (1);
	}
	tmp = mini_data->env;
	i = 0;
	while (tmp[i])
	{
		ft_printf("%s\n", tmp[i]);
		i++;
	}
	mini_data->exit_code = 0;
	return (0);
}

int	exit_builtin(t_minishell *mini_data, char **args)
{
	int	return_val;

	return_val = 1;
	if (args && args[2])
	{
		write(STDERR_FILENO, "too many arguments\n", 20);
		mini_data->exit_code = 1;
		return_val = 0;
	}
	ft_printf("exit\n");
	if (args[1] && return_val == 1)
		mini_data->exit_code = ft_atoi(args[1]);
	free_2d(args);
	if (return_val == 1)
		mini_exit(mini_data);
	return (0);
}

int	history_builtin(t_minishell *mini_data, char **args)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = mini_data->history;
	if (args[1])
	{
		ft_printf("history: too many args.\n");
		mini_data->exit_code = 1;
		return (0);
	}
	while (tmp)
	{
		if (tmp->content)
			ft_printf("%d %s\n", i, tmp->content);
		tmp = tmp->next;
		i++;
	}
	mini_data->exit_code = 0;
	return (0);
}

static int	builtin_loop(t_minishell *mini_data, char **args, t_builtin *lst)
{
	int	i;
	int	eq;
	int	strch;

	i = 0;
	eq = -1;
	while (i < 8)
	{
		strch = ft_strlen(args[0]);
		if (strch < ft_strlen(lst[i].cmd))
			strch = ft_strlen(lst[i].cmd);
		eq = ft_strncmp(args[0], lst[i].cmd, strch);
		if (eq == 0)
		{
			eq = lst[i].function(mini_data, args);
			return (eq);
		}
		i++;
	}
	return (-1);
}

int	handle_builtins(t_minishell *mini_data, char **args)
{
	t_builtin	lst[8];
	int			res;

	if (!args || !args[0])
		return (0);
	lst[0] = (t_builtin){"echo", &echo_builtin};
	lst[1] = (t_builtin){"cd", &cd_builtin};
	lst[2] = (t_builtin){"pwd", &pwd_builtin};
	lst[3] = (t_builtin){"export", &export_builtin};
	lst[4] = (t_builtin){"unset", &unset_builtin};
	lst[5] = (t_builtin){"env", &env_builtin};
	lst[6] = (t_builtin){"exit", &exit_builtin};
	lst[7] = (t_builtin){"history", &history_builtin};
	res = builtin_loop(mini_data, args, lst);
	return (res);
}
