/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyardimc <fyardimc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:09:31 by fyardimc          #+#    #+#             */
/*   Updated: 2023/03/29 16:09:39 by fyardimc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_pwd(void)
{
	char	*buffer;

	buffer = ft_calloc(sizeof(char), 4096);
	getcwd(buffer, 4096);
	return (buffer);
}

static void	update_env_path(void)
{
	int		pwdindex;
	char	*value;

	pwdindex = get_env_index("PWD");
	if (pwdindex == -1)
		return ;
	value = ft_strdup(g_shell->env[pwdindex]);
	set_env(ft_strdup("OLDPWD"), get_value(value));
	set_env(ft_strdup("PWD"), get_pwd());
	free(value);
}

static void	put_err(char *arr)
{
	char	*msg;

	msg = strerror(errno);
	ft_putstr_fd("bash : cd: ", 2);
	ft_putstr_fd(arr, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}

int	ft_cd(t_command *cmd)
{
	int		error;
	char	*tmp1;
	char	*tmp2;

	if (!cmd->arguments[1])
	{
		tmp1 = get_value(g_shell->env[get_env_index("USER")]);
		tmp2 = ft_strjoin("/Users/", tmp1);
		chdir(tmp2);
		free(tmp1);
		free(tmp2);
	}
	else
	{
		error = chdir(cmd->arguments[1]);
		if (error)
		{
			put_err(cmd->arguments[1]);
			return (1);
		}
	}
	update_env_path();
	return (0);
}
