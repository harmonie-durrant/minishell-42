/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:39:08 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/29 14:41:36 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*merge_string(char *s1, char *s2, char *s3)
{
	int		len3;
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	len3 = ft_strlen(s3);
	result = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + len3 + 1);
	if (!result)
		return (NULL);
	while (s1[i] != '\0')
		result[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		result[j++] = s2[i++];
	i = 0;
	while (s3[i] != '\0')
		result[j++] = s3[i++];
	result[j] = '\0';
	return (result);
}

char	*find_full_path_2(char **paths, char **args)
{
	int		i;
	char	*full_path;

	i = 0;
	while (paths[i++])
	{
		full_path = merge_string(paths[i - 1], "/", args[0]);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_2d(paths);
			return (full_path);
		}
		free(full_path);
	}
	free_2d(paths);
	return (NULL);
}

char	*find_full_path(char **args, char **env)
{
	char	*path_var;
	char	**paths;

	path_var = get_env("PATH", env);
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	free(path_var);
	return (find_full_path_2(paths, args));
}

int	find_command(t_minishell *mini_data, char **args)
{
	int		file_check;
	char	*full_path;

	full_path = find_full_path(args, mini_data->env);
	if (!full_path)
	{
		file_check = check_file(mini_data, args[0], args[0]);
		if (file_check != 0)
			return (mini_data->exit_code);
		mini_data->exit_code = local_command(mini_data, args);
		return (mini_data->exit_code);
	}
	file_check = check_file(mini_data, full_path, args[0]);
	if (file_check != 0)
	{
		free(full_path);
		return (mini_data->exit_code);
	}
	mini_data->exit_code = create_child(mini_data, full_path, args);
	free(full_path);
	return (mini_data->exit_code);
}
