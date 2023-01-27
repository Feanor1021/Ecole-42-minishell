/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_reds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:31:06 by makbulut          #+#    #+#             */
/*   Updated: 2022/07/02 18:46:10 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "minishell.h"
#include "42-Libft/libft.h"

static int	getflags(t_stream *stream)
{
	int	flags;

	flags = O_CREAT | O_WRONLY;
	if (stream->appendmode)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	return (flags);
}

static int	redirectout(t_command *cmd, t_stream *stream)
{
	if (cmd->out != 1 && !g_mini->issubshell)
		close(cmd->out);
	cmd->out = open(stream->path, getflags(stream), 0666);
	if (cmd->out == -1)
	{
		ft_puterrno_msg(stream->path);
		return (0);
	}
	return (1);
}

static int	redirectin(t_command *cmd, t_stream *stream)
{
	if (cmd->in != 0 && !g_mini->issubshell)
		close(cmd->in);
	cmd->in = open(stream->path, O_RDONLY);
	if (cmd->in == -1)
	{
		ft_puterrno_msg(stream->path);
		return (0);
	}
	return (1);
}

int	ft_open_reds(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->redirections && cmd->redirections[i])
	{
		if (cmd->redirections[i]->type == STREAM_OUT)
		{
			if (!redirectout(cmd, cmd->redirections[i]))
				return (0);
		}
		else if (cmd->redirections[i]->type == STREAM_IN)
			if (!redirectin(cmd, cmd->redirections[i]))
				return (0);
		i++;
	}
	return (1);
}
