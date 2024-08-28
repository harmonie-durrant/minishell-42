/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_dollar_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:10:07 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/28 11:18:55 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_no_dollar(char *str, t_v2d *ij, char **formatted)
{
	if (str[ij->x] != '$')
	{
		*formatted = add_char(*formatted, str[ij->x]);
		ij->x = ij->x + 1;
		return (1);
	}
	return (0);
}

int	check_exit_code(char *str, t_v2d *ij, char **formatted,
		t_minishell *mini_data)
{
	char	*tmp;

	if (str[ij->x + 1] == '?')
	{
		tmp = ft_itoa(mini_data->exit_code);
		*formatted = add_str(*formatted, tmp);
		free(tmp);
		ij->x = ij->x + 2;
		return (1);
	}
	return (0);
}

void	merge_env_var(char **formatted, char *tmp, char *tmp_env_val)
{
	if (tmp_env_val)
	{
		*formatted = add_str(*formatted, tmp_env_val);
		free(tmp_env_val);
	}
	else
		*formatted = merge_string(*formatted, "$", tmp);
	free(tmp);
}

int	check_dollar(char *str, t_v4d *data, char **formatted,
		t_minishell *mini_data)
{
	char	*tmp;
	char	*tmp_env_val;
	t_v2d	*ij;
	t_v2d	*ignore;

	ij = data->ij;
	ignore = data->ignore;
	if (str[ij->x + 1] && ignore->y == 0)
	{
		if (check_exit_code(str, ij, formatted, mini_data) == 1)
			return (1);
		ij->y = ij->x + 1;
		while (str[ij->y] && (ft_isalnum(str[ij->y]) || str[ij->y] == '_'))
			ij->y = ij->y + 1;
		tmp = ft_substr(str, ij->x + 1, ij->y - ij->x - 1);
		tmp_env_val = get_env(tmp, mini_data->env);
		merge_env_var(formatted, tmp, tmp_env_val);
		ij->x = ij->y;
		return (1);
	}
	return (0);
}
