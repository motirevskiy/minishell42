/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparsing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:50:02 by truthe            #+#    #+#             */
/*   Updated: 2022/06/08 15:50:16 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_preparsing(void)
{
	int	i;

	i = -1;
	if (check_spaces() == -1)
		return (-105);
	g_o.splited = ft_split_mod(g_o.g_l, ' ');
	if (!g_o.splited)
		return (-104);
	while (g_o.splited[++i])
	{
		if (!g_o.args)
			g_o.args = ft_lstnew(ft_strdup(g_o.splited[i]));
		else
			ft_lstadd_back(&g_o.args, ft_lstnew(ft_strdup(g_o.splited[i])));
		free(g_o.splited[i]);
		g_o.splited[i] = NULL;
	}
	ft_check_syntax();
	if (g_o.error_f > 0)
	{
		ft_check_list();
		ft_ihatenorminette();
	}
	return (g_o.error_f);
}
