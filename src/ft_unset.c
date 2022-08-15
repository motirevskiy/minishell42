/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:13:36 by truthe            #+#    #+#             */
/*   Updated: 2022/06/07 17:46:07 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_unset(char *str, char **env)
{
	int	j;
	int	len;

	j = 0;
	if (!str)
		return ;
	len = ft_strlen(str);
	while (env[j] && ft_strnstr(env[j], str, len) == 0)
		j++;
	if (env[j] != NULL)
		env[j][0] = 0;
}
