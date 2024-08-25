/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:53:37 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/25 13:32:56 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "minishell.h"
# include <sys/wait.h>
# define P_CHARS "|"
# define P_DOUBLES ""

typedef struct tree_s
{
	char			*data;
	struct tree_s	*left;
	struct tree_s	*right;
}				t_tree;

typedef struct s_minishell
{
	char	**env;
	int		exit_code;
	t_list	*history;
	t_tree	*tree;
}	t_minishell;

typedef struct pipepids_s
{
	int		*pipe_fd;
	pid_t	*pids;
}				t_pipepids;

t_tree	*create_node(char *data);
int		add_node(t_tree *tree, char *data);
void	print_tree(t_tree *root, int indent);
void	destroy_tree(t_tree *tree);
int		get_seperator_index(char *input);
int		execute_tree(t_minishell *ms_data, t_tree *branch);
int		execute_command(t_minishell *ms_data, t_tree *branch);


t_tree	*process_tree(char *input);

int		execute_piped_commands(t_minishell *ms_data, t_tree *branch);
void	exec_left_pipe(t_minishell *ms_data, t_tree *branch, int *pipe_fd);
void	exec_right_pipe(t_minishell *mini_data, t_tree *branch, int *pipe_fd);
void	leftright_pid(t_minishell *ms_data, t_tree *branch, t_pipepids *pipepids);

#endif
