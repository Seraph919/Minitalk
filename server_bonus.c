/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:27:30 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/19 18:25:52 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void handler(int sig, siginfo_t *info, void *context) 
{
    int n;
    (void)context;
    static char c = 0;
    static int count = 0;
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

int main()
{
    ft_putstr("\033[0;33m");
    ft_putstr("The server's running with PID: ");
    ft_putstr("\033[0m"); 
    ft_putnbr(getpid());
    ft_putchar('\n');
    ft_putstr("\033[0;32m");
    struct sigaction sa = {0};
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
    {
    }
    return 0;
}
