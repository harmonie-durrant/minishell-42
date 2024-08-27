/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:33:51 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 11:44:31 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"
# include <unistd.h>
# include <sys/stat.h>

typedef struct builtin
{
	char	*cmd;
	int		(*function)(t_minishell *mini_data, char **args);
}				t_builtin;

int	handle_builtins(t_minishell *mini_data, char **args);

int	echo_builtin(t_minishell *mini_data, char **args);
int	cd_builtin(t_minishell *mini_data, char **args);
int	pwd_builtin(t_minishell *mini_data, char **args);
int	export_builtin(t_minishell *mini_data, char **args);
int	unset_builtin(t_minishell *mini_data, char **args);
int	env_builtin(t_minishell *mini_data, char **args);
int	exit_builtin(t_minishell *mini_data, char **args);

int	history_builtin(t_minishell *mini_data, char **args);

int	change_to_home(t_minishell *ms_data);
int	change_to_directory(char *directory, t_minishell *ms_data);
int	save_previous_directory(t_minishell *ms_data);
int	change_to_previous(t_minishell *ms_data);

int	ft_export(char *name, const char *value, int overwrite,
		t_minishell *mini_data);

#endif