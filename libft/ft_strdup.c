/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:40:50 by kferterb          #+#    #+#             */
/*   Updated: 2022/06/05 19:09:42 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		str[j] = s1[j];
	str[j] = '\0';
	return (str);
}

char	*ft_strdup_mod(char *s1, int n)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		str[j] = s1[j];
	str[j] = '\0';
	if (n == 1)
	{
		free (s1);
		s1 = NULL;
	}
	return (str);
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int i;

// 	i = 0;
// 	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
// 		i++;
// 	return (s1[i] - s2[i]);
// }
