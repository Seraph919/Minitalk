/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:58:47 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/16 14:16:16 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int sig) 
{
    int n;
    static char c = 0;
    static int count = 0;
    if (sig == SIGUSR1)
        n = 1;
    else if (sig == SIGUSR2)
        n = 0;
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
    ft_putstr("The server's running with PID: ");
    ft_putnbr(getpid());
    ft_putchar('\n');
    signal(SIGUSR1, handle_signal);
    signal(SIGUSR2, handle_signal);
    while (1)
        pause();
    return 0;
}