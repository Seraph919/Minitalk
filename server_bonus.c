/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:27:30 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/22 14:24:18 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sigaction_handler(int sig, siginfo_t *info, void *context)
{
	int				n;
	static char		c;
	static int		count;

	(void) context;
	if (sig == SIGUSR1)
	{
		n = 1;
		kill(info->si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		n = 0;
		kill(info->si_pid, SIGUSR2);
	}
	c = c << 1 | n;
	count++;
	if (count == 8)
	{
		ft_putchar(c);
		count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_putstr("\033[0;31m\n"
		"███╗   ███╗        ██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗\n"
		"████╗ ████║        ██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝\n"
		"██╔████╔██║        ██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗\n"
		"██║╚██╔╝██║        ██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║\n"
		"██║ ╚═╝ ██║███████╗██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║\n"
		"╚═╝     ╚═╝╚══════╝╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝\n");
	ft_putstr("_____________________ The server's running with PID: \033[0m");
	ft_putnbr(getpid());
	ft_putstr("\033[0;31m _____________________\n");
	ft_putstr("\033[0m ");
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	action.sa_sigaction = sigaction_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
	}
	return (0);
}
