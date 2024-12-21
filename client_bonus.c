/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:27:41 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/21 21:58:47 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_signal(int sig)
{
	(void) sig;
	if (sig == SIGUSR1)
	{
		ft_putstr("\033[0;32m");
		ft_putstr("SIGUSR1 has been recieved (aka '1')\n");
		ft_putstr("\033[0m");
	}
	if (sig == SIGUSR2)
	{
		ft_putstr("\033[0;31m");
		ft_putstr("SIGUSR2 has been recieved (aka '0')\n");
		ft_putstr("\033[0m");
	}
}

static void	_while(char *s, int n, int prc_id)
{
	int		d;
	int		i;

	while (s[n])
	{
		i = 7;
		while (i >= 0)
		{
			d = (s[n] >> i) & 1;
			if (d == 0)
				kill(prc_id, SIGUSR2);
			else
			{
				kill(prc_id, SIGUSR1);
			}
			usleep(150);
			i--;
		}
		n++;
	}
}

int	main(int ac, char **av)
{
	int					n;
	int					prc_id;
	struct sigaction	action;

	if (ac == 3)
	{
		n = 0;
		prc_id = atoi(av[1]);
		action.sa_handler = handle_signal;
		if (sigaction(SIGUSR1, &action, NULL) == -1)
			exit(-1);
		if (sigaction(SIGUSR2, &action, NULL) == -1)
			exit(-1);
		_while(av[2], n, prc_id);
	}
}
