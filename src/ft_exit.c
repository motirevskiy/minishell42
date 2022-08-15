/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:12:49 by truthe            #+#    #+#             */
/*   Updated: 2022/06/07 16:31:03 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exit(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		printf ("exit\n");
		exit (1);
	}
	while (str[i] && str[i] != '\n')
	{
		if (str[i] > '9' || str[i] < '0' || ft_atoi(&str[i]) > 255)
		{
			printf("minishell: exit: %s: numeric argument required\n", str);
			return ;
		}
		i++;
	}
	printf("%s\n", str);
	exit(1);
}
