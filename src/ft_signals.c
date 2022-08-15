/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:50:00 by truthe            #+#    #+#             */
/*   Updated: 2022/06/08 17:50:11 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_proc_signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		signal(SIGINT, ft_proc_signal_handler);
	}
	if (signum == SIGQUIT)
	{
		write(1, "\n", 1);
		signal(SIGQUIT, ft_proc_signal_handler);
	}
}

void	ft_handler(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \n", 3);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_signals(void)
{
	struct sigaction	sa;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	sa.sa_handler = ft_handler;
	sigaction(SIGINT, &sa, NULL);
}
