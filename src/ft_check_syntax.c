/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:23:42 by cgretche          #+#    #+#             */
/*   Updated: 2022/06/08 15:53:18 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	can_i_open(t_lst *tmp)
{
	if ((!ft_strncmp(tmp->str, ">", 1)
			|| !ft_strncmp(tmp->str, "<", 1)
			|| !ft_strncmp(tmp->str, ">>", 2)
			|| !ft_strncmp(tmp->str, "<<", 2)
			|| !ft_strncmp(tmp->str, "<>", 2))
		&& (tmp->next && (!ft_strncmp(tmp->next->str, ">", 1)
				|| !ft_strncmp(tmp->next->str, "<", 1)
				|| !ft_strncmp(tmp->next->str, ">>", 2)
				|| !ft_strncmp(tmp->next->str, "<<", 2)
				|| !ft_strncmp(tmp->next->str, "<>", 2))))
	{
		g_o.error_f = -121;
		return (1);
	}
	else if ((!ft_strncmp(tmp->str, ">", 1)
			|| !ft_strncmp(tmp->str, "<", 1)
			|| !ft_strncmp(tmp->str, ">>", 2)
			|| !ft_strncmp(tmp->str, "<<", 2)
			|| !ft_strncmp(tmp->str, "<>", 2))
		&& !tmp->next)
	{
		g_o.error_f = -121;
		return (1);
	}
	return (0);
}

void	ft_check_syntax(void)
{
	t_lst	*tmp;
	int		i;

	tmp = g_o.args;
	i = ft_lstsize(tmp);
	while (tmp && g_o.error_f != -121)
	{
		if (can_i_open(tmp))
			break ;
		if (i == 1 && (!ft_strncmp(tmp->str, ">", 1)
				|| !ft_strncmp(tmp->str, "<", 1)
				|| !ft_strncmp(tmp->str, "|", 1)))
			g_o.error_f = -121;
		else if (!ft_strncmp(tmp->str, "|", 1)
			&& (tmp->next && !ft_strncmp(tmp->next->str, "|", 1)))
			g_o.error_f = -121;
		else if ((!ft_strncmp(tmp->str, ">", 1)
				|| !ft_strncmp(tmp->str, "<", 1))
			&& (tmp->next && ((tmp->next->next
						&& !ft_strncmp(tmp->next->next->str, "|", 1))
					|| !ft_strncmp(tmp->next->str, "|", 1))))
			g_o.error_f = -121;
		tmp = tmp->next;
	}
}
