/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:59:05 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/22 13:52:06 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	_while_(char *s, int process_id)
{
	int		n;
	int		d;
	int		i;

	n = 0;
	while (s[n])
	{
		i = 7;
		while (i >= 0)
		{
			d = (s[n] >> i) & 1;
			if (d == 0)
				kill(process_id, SIGUSR2);
			else
				kill(process_id, SIGUSR1);
			usleep(60);
			i--;
		}
		n++;
	}
}

int	main(int ac, char **av)
{
	int		process_id;

	if (ac == 3)
	{
		process_id = ft_atoi(av[1]);
		_while_(av[2], process_id);
	}
	if (ac != 3)
	{
		ft_putstr("\033[0;31mPlease enter the correct paramiters :\n");
		ft_putstr("\033[0m./client\033[0;32m <PID> \033[0m""text""\n");
		exit(-1);
	}
}
