/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:13:07 by truthe            #+#    #+#             */
/*   Updated: 2022/06/07 17:41:44 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_export_sort(char **env2)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (env2[j])
	{
		i = 0;
		while (env2[i + 1])
		{
			if (ft_strcmp(env2[i], env2[i + 1]) > 0)
			{
				tmp = env2[i];
				env2[i] = env2[i + 1];
				env2[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}
