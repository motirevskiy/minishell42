/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:13:00 by truthe            #+#    #+#             */
/*   Updated: 2022/06/07 17:41:14 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_export_pars2(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = &str[i];
	{
		while (tmp[i] && tmp[i] != '=')
			i++;
		tmp[i] = 0;
		j = 0;
		while (g_o.env[j] && ft_strnstr(g_o.env[j], tmp, i) == 0)
			j++;
		tmp[i] = '=';
		if (g_o.env[j] != NULL)
		{	
			free(g_o.env[j]);
			g_o.env[j] = ft_strdup(tmp);
		}
		else
			g_o.env[size_env(g_o.env)] = ft_strdup(tmp);
	}
}

void	ft_export_pars(char *str)
{
	int		i;
	int		chetchik;
	char	*tmp;

	i = 0;
	chetchik = 0;
	tmp = &str[i];
	while (str[i])
	{
		if (str[i] == ' ')
		{
			printf("export arguments error\n");
			break ;
		}
		if (str[i] == '=')
			chetchik++;
		i++;
	}
	i = 0;
	if (chetchik > 1)
		printf ("export arguments error\n");
	else if (chetchik == 1)
		ft_export_pars2(str);
}
