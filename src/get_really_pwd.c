/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_really_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:13:50 by truthe            #+#    #+#             */
/*   Updated: 2022/06/07 17:53:18 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	get_really_pwd(void)
{
	char	*get;
	int		i;

	i = 0;
	get = malloc(1000);
	getcwd(get, 1000);
	while (ft_strnstr(g_o.env[i], "PWD=", 4) == 0)
	i++;
	if (g_o.env[i] != NULL)
	{
		free(g_o.env[i]);
		g_o.env[i] = ft_strjoin("PWD=", get);
	}
	free(get);
}
