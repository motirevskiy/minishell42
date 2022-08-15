/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_old_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:13:45 by truthe            #+#    #+#             */
/*   Updated: 2022/06/07 17:52:09 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	get_old_pwd(void)
{
	char	*get;
	int		i;

	i = 0;
	get = malloc(1000);
	getcwd(get, 1000);
	while (ft_strnstr(g_o.env[i], "OLDPWD=", 7) == 0)
	i++;
	if (g_o.env[i] != NULL)
	{
		free(g_o.env[i]);
		g_o.env[i] = ft_strjoin("OLDPWD=", get);
	}
	free(get);
}
