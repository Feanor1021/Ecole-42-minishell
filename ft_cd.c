/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:06:33 by makbulut          #+#    #+#             */
/*   Updated: 2022/08/21 13:23:41 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "minishell.h"
#include "42-Libft/libft.h"

static char	*get_pwd(void)
{
	char	*buffer;

	buffer = ft_calloc(sizeof(char), 4096);
	getcwd(buffer, 4096);
	return (buffer);
}

static void	change_env_path(void)
{
	int		pwdindex;
	char	*value;

	pwdindex = ft_getenvindex("PWD");
	if (pwdindex == -1)
		return ;
	value = ft_strdup(g_mini->env[pwdindex]);
	ft_setenv("OLDPWD", value);
	ft_setenv("PWD", get_pwd());
	free(value);
}

static void	puterr(char *str)
{
	char	*msg;

	msg = strerror(errno);
	ft_putstr_fd("bash : cd: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}

int	ft_cd(t_command *cmd)
{
	int		err;
	char	*tmp1;
	char	*tmp2;

	if (!cmd->arguments[1])
	{
		tmp1 = ft_get_value(g_mini->env[ft_getenvindex("USER")]);
		tmp2 = ft_strjoin("/Users/", tmp1);
		chdir(tmp2);
		free(tmp1);
		free(tmp2);
	}
	else
	{
		err = chdir(cmd->arguments[1]);
		if (err)
		{
			puterr(cmd->arguments[1]);
			return (1);
		}
	}
	return (0);
	change_env_path();
}
