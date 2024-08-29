/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:02:04 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/29 14:39:43 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_error(char *pre, char *post)
{
	ft_putstr_fd(pre, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(post, 2);
}

int check_file(t_minishell *mini_data, char *file, char *first_arg)
{
    struct stat buf;

    if (stat(file, &buf) == -1)
    {
        ft_print_error(first_arg, strerror(errno));
        mini_data->exit_code = 127;
        return (1);
    }

    if (S_ISDIR(buf.st_mode))
    {
        ft_print_error(first_arg, "Is a directory\n");
        mini_data->exit_code = 126;
        return (1);
    }
    if (access(file, F_OK) == -1)
    {
		ft_print_error(first_arg, "command not found\n");
        mini_data->exit_code = 127;
        return (1);
    }
    if (access(file, X_OK) == -1)
    {
        ft_print_error(first_arg, "Permission denied\n");
        mini_data->exit_code = 126;
        return (1);
    }
    return (0);
}
