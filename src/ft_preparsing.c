/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:36:54 by cgretche          #+#    #+#             */
/*   Updated: 2022/06/08 16:51:20 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	*ft_delete_q(t_lst *lst)
{
	char	*tmp;
	int		i;
	int		n;

	i = ft_strlen(lst->str);
	n = 0;
	tmp = malloc(sizeof(char *) * i - 1);
	if (!tmp)
		g_o.error_f = -106;
	i = -1;
	while (lst->str[++i])
	{
		if (lst->str[i] == '"' || lst->str[i] == '\'')
			i++;
		tmp[n] = lst->str[i];
		n++;
	}
	tmp[n] = '\0';
	free(lst->str);
	lst->str = ft_strdup(tmp);
	free(tmp);
	return (lst);
}

static void	*ft_check_dollar_in_q(t_lst *tmp)
{
	g_o.i = -1;
	g_o.j = 0;
	while (tmp->str[++g_o.i])
	{
		if (tmp->str[g_o.i] == '"' || tmp->str[g_o.i] == '\'')
			g_o.j++;
		if (g_o.j == 2)
		{
			while (tmp->str[++g_o.i])
			{
				if (tmp->str[g_o.i] == '$')
				{
					tmp->str = parse_dollar(tmp->str);
					break ;
				}
			}
		}
	}
	return (tmp);
}

t_lst	*ft_check_q(t_lst *tmp)
{
	int	i;

	i = -1;
	while (tmp->str[++i])
	{
		if (tmp->str[i] == '"' || tmp->str[i] == '\'')
		{
			if (ft_strlen(tmp->str) == 2
				&& (tmp->str[i] == '\'' || tmp->str[i] == '"'))
				tmp->str = NULL;
			else
			{
				tmp = ft_check_dollar_in_q(tmp);
				tmp = ft_delete_q(tmp);
			}
			tmp->pipe_flag = 0;
			tmp->meta_flag = 1;
			return (tmp);
		}
		else if (tmp->str[i] == '$')
			tmp->str = parse_dollar(tmp->str);
	}
	return (tmp);
}

void	ft_check_list(void)
{
	t_lst	*tmp;

	if (g_o.args->pipe_flag == 1)
		g_o.args = g_o.args->next;
	tmp = g_o.args;
	while (tmp && tmp->str != NULL)
	{
		tmp = ft_check_q(tmp);
		if (tmp->str != NULL && (ft_strncmp(tmp->str, "|", 1) == 0)
			&& !tmp->meta_flag)
		{
			tmp = ft_check_pipe(tmp);
			break ;
		}
		tmp->pipe_flag = 0;
		if (tmp->str != NULL && !tmp->pipe_flag
			&& (ft_strncmp(tmp->str, ">", 1) == 0
				|| ft_strncmp(tmp->str, "<", 1) == 0) && !tmp->meta_flag)
			tmp = ft_parse_redirect(tmp);
		if (tmp->str != NULL && !tmp->pipe_flag)
				g_o.count_ex++;
		tmp = tmp->next;
	}
	ft_parse_execve();
	free(tmp);
}

void	ft_ihatenorminette(void)
{
	ft_dollar_question(g_o.final->execve);
	if (ft_strnstr(g_o.final->execve[0], "cd", ft_strlen(g_o.final->execve[0])))
		ft_cd(g_o.final->execve[1], g_o.env);
	else if (ft_strnstr(g_o.final->execve[0], "exit",
			ft_strlen(g_o.final->execve[0])))
		ft_exit(g_o.final->execve[1]);
	else if (ft_strnstr(g_o.final->execve[0], "unset",
			ft_strlen(g_o.final->execve[0])))
		ft_unset(g_o.final->execve[1], g_o.env);
	else if (ft_strnstr(g_o.final->execve[0], "export",
			ft_strlen(g_o.final->execve[0])) && g_o.final->execve[1]
		&& *g_o.final->execve[1])
		ft_export(g_o.final->execve[1]);
	else
		pipe_execute_comand();
}
