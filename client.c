/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:59:05 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/21 22:15:24 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int		d;
	int		n;
	int		i;
	int		process_id;

	if (ac == 3)
	{
		process_id = ft_atoi(av[1]);
		n = 0;
		while (av[2][n])
		{
			i = 7;
			while (i >= 0)
			{
				d = (av[2][n] >> i) & 1;
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
}
