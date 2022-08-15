/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:41:35 by truthe            #+#    #+#             */
/*   Updated: 2022/06/08 15:33:35 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	norm_fd(int *fd, int *fd_2, t_lst *tmp)
{
	if (tmp->fd_in == -2)
	{
		close(fd_2[1]);
		dup2(fd_2[0], 0);
	}
	else
		dup2(tmp->fd_in, 0);
	if (tmp->fd_out == -2)
	{
		close(fd[0]);
		dup2(fd[1], 1);
	}
	else
		dup2(tmp->fd_out, 1);
}

void	norm_fd_lost(t_lst *tmp, int *fd)
{
	if (tmp->fd_in == -2)
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
	else
		dup2(tmp->fd_in, 0);
}

void	close_fd(int *fd, int *fd_2, int i)
{
	if (i % 2 != 0 && i != 0)
	{
		close(fd[0]);
		close(fd[1]);
	}
	else if (i % 2 == 0 && i != 0)
	{
		close(fd_2[0]);
		close(fd_2[1]);
	}
}

void	norm_fd_first(t_lst *tmp, int *fd)
{
	if (tmp->fd_out == -2)
	{
		close(fd[0]);
		dup2(fd[1], 1);
	}
	else
		dup2(tmp->fd_out, 1);
	if (tmp->fd_in != -2)
		dup2(tmp->fd_in, 0);
}

void	wait_commands(pid_t *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		waitpid(p[i], NULL, 0);
		i++;
	}
	free(p);
}
