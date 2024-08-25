/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:32:37 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 15:48:27 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_directory(const char *path)
{
	int			ret;
	struct stat	stats;

	if (stat(path, &stats) != 0)
		return (0);
	ret = S_ISDIR(stats.st_mode);
	return (ret);
}

int	change_to_previous(t_minishell *mini_data)
{
	char	*previous_dir;
	int		ret;

	previous_dir = get_env("OLDPWD", mini_data->env);
	if (!previous_dir)
		return (-1);
	ret = is_directory(previous_dir);
	if (!ret)
	{
		ft_printf("%s: Not a directory.\n", previous_dir);
		return (2);
	}
	ret = chdir(previous_dir);
	if (ret != 0)
	{
		ft_printf("%s\n", previous_dir);
		return (1);
	}
	ft_printf("%s\n", previous_dir);
	ret = save_previous_directory(mini_data);
	return (ret);
}

int	save_previous_directory(t_minishell *mini_data)
{
	char	*previous_dir;

	previous_dir = getcwd(NULL, 0);
	if (!previous_dir)
		return (1);
	if (setenv("OLDPWD", get_env("PWD", mini_data->env), 1) != 0)
	{
		free(previous_dir);
		return (1);
	}
	if (setenv("PWD", previous_dir, 1) != 0)
	{
		free(previous_dir);
		return (1);
	}
	free(previous_dir);
	return (0);
}

int	change_to_home(t_minishell *mini_data)
{
	int		ret;
	char	*home;

	home = get_env("HOME", mini_data->env);
	if (!home)
		return (1);
	if (!is_directory(home))
	{
		write(STDERR_FILENO, "No such file or directory\n", 27);
		return (1);
	}
	ret = chdir(home);
	if (ret != 0)
	{
		write(STDERR_FILENO, "No such file or directory\n", 27);
		return (1);
	}
	ret = save_previous_directory(mini_data);
	return (ret);
}

int	change_to_directory(char *directory, t_minishell *mini_data)
{
	int	ret;

	if (directory[0] == '~')
	{
		directory = ft_strjoin(get_env("HOME", mini_data->env), directory + 1);
		if (!directory)
			return (1);
	}
	ret = is_directory(directory);
	if (!ret)
	{
		write(STDERR_FILENO, "No such file or directory\n", 27);
		return (1);
	}
	ret = chdir(directory);
	if (ret != 0)
	{
		write(STDERR_FILENO, "No such file or directory\n", 27);
		return (1);
	}
	ret = save_previous_directory(mini_data);
	return (ret);
}
