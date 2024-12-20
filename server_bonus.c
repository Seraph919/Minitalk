/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:27:30 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/20 18:22:37 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void sigaction_handler(int sig, siginfo_t *info, void *context) 
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

// void sigtstp_handler(int sig)
// {
//     (void) sig;
//     ft_putstr("\033[0m");
//     ft_putstr("\nThe process has Successfully been ");
//     kill(getpid(), SIGKILL);
// }

int main()
{
    ft_putstr("\033[0;33m");
    ft_putstr("The server's running with PID: ");
    ft_putstr("\033[0m"); 
    ft_putnbr(getpid());
    ft_putchar('\n');
    ft_putstr("\033[0;32m");
    struct sigaction action = {0};
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = sigaction_handler;
    sigemptyset(&action.sa_mask);
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    // signal(SIGTSTP, sigtstp_handler);
    while (1)
    {
    }
    return 0;
}
