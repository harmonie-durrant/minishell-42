/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:31:13 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 14:53:42 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/ft/include/libft.h"
# include <signal.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include "tree.h"
# include "builtins.h"

typedef struct s_v2d
{
	int	x;
	int	y;
}	t_v2d;

// t_minishell
t_minishell	*init_minishell(char const *envp[]);
void		free_minishell(t_minishell *mini_data);
void		mini_exit(t_minishell *mini_data);

// parse
void		parse_input(char *input, t_minishell *mini_data);

// command and child
int			find_command(t_minishell *mini_data, char **args);
int			create_child(t_minishell *mini_data, char *full_path, char **args);
char		*merge_string(char *s1, char *s2, char *s3);
char		*find_full_path(char **args, char **env);
int			is_executable(char **args);
int			local_command(t_minishell *mini_data, char **args);
char		**get_args(char *data);
int			get_redirection(t_minishell *mini_data, char **args);

// env
char		*get_env(char *label, char **env);
int			get_big(int a, int b);
char		*create_env(const char *name, const char *value);
void		add_env_var_to_list(char *new_var, t_minishell *mini_data);
int			unset_env(const char *name, t_minishell *ms_data);
char		*get_env(char *label, char **env);

// misc
char		*ft_strndup(const char *s, size_t n);
char		*remove_double_quotes(const char *str);
void		free_2d(char **arr);
void		add_arg(char *data, int *i, char **args, t_v2d *ignore);
char		*format_dollar(char *str, t_minishell *mini_data);

#endif