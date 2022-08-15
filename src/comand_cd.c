/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:12:31 by truthe            #+#    #+#             */
/*   Updated: 2022/06/07 17:56:29 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_pwd(void)
{
	char	*pwd;

	pwd = malloc(1000);
	getcwd(pwd, 1000);
	printf ("%s\n", pwd);
	free(pwd);
}

void	search_lost_home(char **env)
{
	int	i;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "HOME=", 5) == 0)
		i++;
	if (env[i])
		chdir(&env[i][5]);
	else
		printf ("error home directory\n");
}

int	ft_cd(char *str, char **env)
{
	get_old_pwd ();
	if (!str)
	{
		search_lost_home(env);
		return (0);
	}
	else if (str[0] == '~' && !str[1])
	{
		search_lost_home(env);
	}
	else if (chdir(str) == -1)
	{
		printf("minishell: cd: error path\n");
		return (0);
	}
	get_really_pwd();
	return (0);
}
