/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:59:05 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/16 14:16:35 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void foo(int sig)
{
    (void) sig;
    ft_putstr("confirmed!");
    ft_putchar('\n');
}
void foo2(int sig)
{
    (void) sig;
    return;
}
int main(int ac, char **av)
{
    int d;
    int n = 0;
    int i;

    if (ac == 3)
    {
        int PID = atoi(av[1]);
        signal(SIGUSR1, foo);
        signal(SIGUSR2, foo2);
        while(av[2][n])
        {
            i = 7;
            while (i >= 0)
            {
                d = (av[2][n] >> i) & 1;
                if (d == 0)
                {
                    kill(PID, SIGUSR2);
                    ft_putstr("THE BIT 0 HAS BEEN SENT TO ");
                    ft_putnbr(PID);
                    ft_putchar('\n');
                }
                else
                {
                    kill(PID, SIGUSR1);
                    ft_putstr("THE BIT 1 HAS BEEN SENT TO ");
                    ft_putnbr(PID);
                    ft_putchar('\n');
                }
                usleep(100);
                i--;
            }
            n++;
        }
    }
}
