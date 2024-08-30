/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:10:42 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/29 15:36:07 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "minishell.h"

int	get_index_arg(char **args, char *str);
int	redirect_double_input(t_minishell *mini_data, char **args);
int	redirect_double_output(t_minishell *mini_data, char **args);
int	redirect_output(t_minishell *mini_data, char **args);
int	redirect_input(t_minishell *mini_data, char **args);
int	semicolon_handler(t_minishell *mini_data, char **args);
int	check_redirect_permissions(t_minishell *mini_data, char	*file);

#endif