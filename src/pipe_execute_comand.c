/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execute_comand.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:34:32 by truthe            #+#    #+#             */
/*   Updated: 2022/06/08 17:35:23 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

typedef struct s_norm
{
	pid_t	*p;
	int		fd[2];
	int		fd_2[2];
	int		i;
	int		len;
	t_lst	*tmp;
}			t_norm;

char	*find_cmd(char *cmd, char **env)
{
	int		i;
	char	*jn;
	char	*str;
	char	**splt;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	splt = ft_split(env[i] + 5, ':');
	i = 0;
	while (splt[i])
	{
		jn = ft_strjoin(splt[i], "/");
		str = ft_strjoin(jn, cmd);
		free(str);
		if (access(str, F_OK) == 0)
			return (str);
		i++;
	}
	return (0);
}

void	ft_execve(char	**cmd, char **env)
{
	char	*put;

	put = find_cmd(cmd[0], env);
	if (execve(put, cmd, env) == -1)
	{
		printf("error command\n");
		exit(0);
	}
}

void	norm_com(t_lst *tmp)
{
	if (ft_strnstr(tmp->execve[0], "pwd", ft_strlen(tmp->execve[0])))
		ft_pwd();
	else if (ft_strnstr(tmp->execve[0], "env", ft_strlen(tmp->execve[0])))
		ft_print_env(g_o.env);
	else if (ft_strnstr(tmp->execve[0], "export", ft_strlen(tmp->execve[0])))
		ft_export(tmp->execve[1]);
	else
		ft_execve(tmp->execve, g_o.env);
	exit(0);
}

void	child_process(t_norm *m)
{
	if (m->i == 0)
		norm_fd_first(m->tmp, m->fd);
	else if (m->i % 2 == 0 && m->i != m->len - 1)
		norm_fd(m->fd, m->fd_2, m->tmp);
	else if (m->i % 2 != 0 && m->i != m->len - 1)
		norm_fd(m->fd_2, m->fd, m->tmp);
	else if (m->i == m->len - 1 && m->len > 1)
	{
		if (m->i % 2 != 0)
			norm_fd_lost(m->tmp, m->fd);
		else if (m->i % 2 == 0)
			norm_fd_lost(m->tmp, m->fd_2);
		if (m->tmp->fd_out != -2)
			dup2(m->tmp->fd_out, 1);
	}
	norm_com(m->tmp);
}

void	pipe_execute_comand(void)
{
	t_norm	m;

	m.i = 0;
	m.tmp = g_o.final;
	m.len = ft_lstsize(m.tmp);
	m.p = (pid_t *) malloc(sizeof(pid_t) * (m.len + 1));
	while (m.tmp && m.i < m.len)
	{
		if (m.i % 2 == 0 && m.len - 1 != m.i)
			pipe (m.fd);
		else if (m.i % 2 != 0 && m.len - 1 != m.i)
			pipe(m.fd_2);
		m.p[m.i] = fork();
		if (m.p[m.i] == 0)
			child_process(&m);
		close_fd(m.fd, m.fd_2, m.i);
		m.i++;
		m.tmp = m.tmp->next;
	}
	wait_commands(m.p);
	g_o.gollar = 0;
}
