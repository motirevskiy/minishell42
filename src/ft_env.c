/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:12:41 by truthe            #+#    #+#             */
/*   Updated: 2022/06/07 16:30:23 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	save_env(char **env, t_shell *e)
{
	int	i;

	i = -1;
	while (env[++i])
		e->env_save[i] = ft_strdup(env[i]);
	e->env_save[i] = NULL;
}

int	size_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}
