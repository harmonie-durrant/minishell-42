/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbryento <rbryento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:08:53 by rbryento          #+#    #+#             */
/*   Updated: 2024/08/27 16:47:29 by rbryento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_n_flag(int *i, char **args)
{
	int	flag_n;

	flag_n = 0;
	if (args[1] && !ft_strncmp(args[1], "-n", 2))
	{
		flag_n = 1;
		*i = *i + 1;
	}
	return (flag_n);
}

char	*add_char(char *str, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	return (new_str);
}

char	*add_str(char *str, char *add)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = ft_calloc(ft_strlen(str) + ft_strlen(add) + 1, sizeof(char));
	while (str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	i = 0;
	while (add[i])
	{
		new_str[j] = add[i];
		i++;
		j++;
	}
	return (new_str);
}

char	*format_dollar(char *str, t_minishell *mini_data)
{
	char	*tmp;
	char	*tmp_env_val;
	char	*formatted;
	int		i;
	int		j;
	t_v2d	ignore;

	i = 0;
	ignore.x = 0;
	ignore.y = 0;
	formatted = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '\'' && ignore.x == 0)
		{
			ignore.y = !ignore.y;
			formatted = add_char(formatted, str[i]);
			i++;
			continue ;
		}
		if (str[i] == '\"' && ignore.y == 0)
		{
			ignore.x = !ignore.x;
			formatted = add_char(formatted, str[i]);
			i++;
			continue ;
		}
		if (str[i] != '$')
		{
			formatted = add_char(formatted, str[i]);
			i++;
			continue ;
		}
		if (str[i + 1] && ignore.y == 0)
		{
			if (str[i + 1] == '?')
			{
				tmp = ft_itoa(mini_data->exit_code);
				formatted = add_str(formatted, tmp);
				free(tmp);
				i = i + 2;
				continue ;
			}
			j = i + 1;
			while (str[j] && (ft_isalnum(str[j]) || str[j] == '_'))
				j++;
			tmp = ft_substr(str, i + 1, j - i - 1);
			tmp_env_val = get_env(tmp, mini_data->env);
			if (tmp_env_val)
			{
				formatted = add_str(formatted, tmp_env_val);
				free(tmp_env_val);
			} else {
				formatted = add_char(formatted, '$');
				formatted = add_str(formatted, tmp);
			}
			free(tmp);
			i = j;
			continue ;
		}
		formatted = add_char(formatted, str[i]);
		i++;
	}
	return (formatted);
}

int	echo_builtin(t_minishell *mini_data, char **args)
{
	int		i;
	char	*formatted;
	int		flag_n;

	i = 1;
	flag_n = is_n_flag(&i, args);
	while (args[i])
	{
		formatted = remove_double_quotes(args[i]);
		ft_printf("%s", formatted);
		if (args[i + 1])
			ft_printf(" ");
		i++;
	}
	if (flag_n == 0)
		ft_printf("\n");
	mini_data->exit_code = 0;
	return (0);
}