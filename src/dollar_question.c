/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_question.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:31:43 by truthe            #+#    #+#             */
/*   Updated: 2022/06/08 17:31:29 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_dollar_question(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '$' && str[i][1] == '?')
		{
			free(str[i]);
			str[i] = ft_strdup(ft_itoa(g_o.gollar));
		}
		i++;
	}
}
