/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:44:04 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 11:46:10 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_variable_name(char *name)
{
	int			i;

	i = 0;
	if (!ft_isalpha((unsigned char)name[0]))
	{
		write(STDERR_FILENO, "not a valid identifier\n", 24);
		return (0);
	}
	while (i < ft_strlen(name))
	{
		if (!ft_isalnum(name[i]))
		{
			write(STDERR_FILENO, "not a valid identifier\n", 24);
			return (0);
		}
		i++;
	}
	return (1);
}

int	should_set_variable(char *name, int overwrite, t_minishell *mini_data)
{
	char	*var;
	int		res;

	var = get_env(name, mini_data->env);
	res = (var == NULL || overwrite);
	free(var);
	return (res);
}

void	replace_variable(char *name, char *new_var, t_minishell *mini_data)
{
	unset_env(name, mini_data);
	add_env_var_to_list(new_var, mini_data);
}

int	ft_export(char *name, const char *value, int overwrite,
		t_minishell *mini_data)
{
	char	*new_var;

	new_var = NULL;
	if (!is_valid_variable_name(name))
		return (1);
	if (!should_set_variable(name, overwrite, mini_data))
		return (0);
	if (value)
		new_var = create_env(name, value);
	else
		new_var = create_env(name, "");
	if (!new_var)
		return (1);
	replace_variable(name, new_var, mini_data);
	return (0);
}
