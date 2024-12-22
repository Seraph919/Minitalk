/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:27:30 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/22 09:50:03 by asoudani         ###   ########.fr       */
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

	ft_putstr("\033[0;33m");
	ft_putstr("\n███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n"
		"████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n"
		"██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\n"
		"██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\n"
		"██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n"
		"╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n");
	ft_putstr("____________ The server's running with PID: ");
	ft_putnbr(getpid());
	ft_putstr(" ____________\n");
	ft_putstr("\033[0m");
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = sigaction_handler;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		exit(-1);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		exit(-1);
	while (1)
	{
	}
	return (0);
}
