/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:41:47 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 13:18:40 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_full_path(char **args,
char *file_path, char *current_dir, char **full_path)
{
	char	*tmp_path;

	tmp_path = merge_string(current_dir, "/", args[0]);
	if (!tmp_path)
	{
		perror("malloc error allocation");
		*full_path = NULL;
		return ;
	}
	if (access(tmp_path, F_OK | R_OK) == 0)
	{
		ft_strlcpy(file_path, tmp_path, ft_strlen(file_path));
		*full_path = file_path;
	}
	else
	{
		free(tmp_path);
		*full_path = NULL;
	}
}

char	*get_full_path(char **args)
{
	char	*full_path;
	char	*current_dir;
	char	*file_path;

	full_path = args[0];
	if (access(full_path, F_OK | R_OK) != 0)
	{
		file_path = malloc(ft_strlen(args[0]) + 1);
		if (!file_path)
			return (NULL);
		current_dir = getcwd(NULL, 0);
		if (!current_dir)
		{
			perror("getcwd error definition");
			free(file_path);
			return (NULL);
		}
		set_full_path(args, file_path, current_dir, &full_path);
		free(current_dir);
		free(file_path);
	}
	return (full_path);
}

int	local_command(t_minishell *mini_data, char **args)
{
	int		status;
	char	*full_path;

	full_path = get_full_path(args);
	if (!full_path)
		return (127);
	if (access(full_path, F_OK | X_OK) == 0)
		status = create_child(mini_data, full_path, args);
	else
	{
		ft_printf("%s: Permission denied.\n", args[0]);
		status = 127;
	}
	return (status);
}
