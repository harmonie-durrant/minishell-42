/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:39:08 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 13:26:57 by rbryento         ###   ########.fr       */
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

char	*find_full_path(char **args, char **env)
{
	char	*path_var;
	char	*full_path;
	char	**paths;
	int		i;

	i = 0;
	path_var = get_env("PATH", env);
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	while (paths[i])
	{
		full_path = merge_string(paths[i], "/", args[0]);
		if (!full_path)
			ft_printf("%s: Command not found.\n", args[0]);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free(paths);
	return (NULL);
}

int	find_command(t_minishell *mini_data, char **args)
{
	int		status;
	char	*full_path;

	status = 0;
	full_path = find_full_path(args, mini_data->env);
	if (full_path != NULL)
	{
		status = create_child(mini_data, full_path, args);
		free(full_path);
		mini_data->exit_code = status;
		return (status);
	}
	status = local_command(mini_data, args);
	if (status == 127)
		printf("%s: Command not found.\n", args[0]);
	mini_data->exit_code = status;
	return (status);
}
