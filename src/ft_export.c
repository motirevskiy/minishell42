/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:13:18 by truthe            #+#    #+#             */
/*   Updated: 2022/06/07 17:44:08 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_export(char *str)
{
	char	**env;
	int		i;

	i = 0;
	if (str)
	{
		ft_export_pars(str);
		return ;
	}
	env = malloc(sizeof(char *) * (size_env(g_o.env) + 1));
	while (g_o.env[i])
	{
			env[i] = g_o.env[i];
			i++;
	}
	env[i] = NULL;
	ft_export_sort(env);
	i = 0;
	while (env[i])
	{
		printf ("declare -x %s\n", env[i]);
		i++;
	}
}
