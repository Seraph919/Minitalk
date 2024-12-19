/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:27:41 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/19 18:20:13 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void handle_signal(int sig)
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
int main(int ac, char **av)
{
    int d;
    int n = 0;
    int i;

    if (ac == 3)
    {
        int PID = atoi(av[1]);
        struct sigaction sa = {0};
        sa.sa_handler = handle_signal;
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        while(av[2][n])
        {
            i = 7;
            while (i >= 0)
            {
                d = (av[2][n] >> i) & 1;
                if (d == 0)
                    kill(PID, SIGUSR2);
                else
                {
                    kill(PID, SIGUSR1);
                }
                usleep(100);
                i--;
            }
            n++;
        }
    }
}
