/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:59:05 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/18 20:36:31 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int sig)
{
    (void) sig;
}
int main(int ac, char **av)
{
    int d;
    int n = 0;
    int i;
    int PID;

    struct sigaction sa = {0};
    sa.sa_handler = signal_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sa.sa_flags = SA_SIGINFO;
    if (ac == 3)
    {
        PID = ft_atoi(av[1]);
        while(av[2][n])
        {
            i = 7;
            while (i >= 0)
            {
                d = (av[2][n] >> i) & 1;
                if (d == 0)
                    kill(PID, SIGUSR2);
                else
                    kill(PID, SIGUSR1);
                usleep(77);
                i--;
            }
            n++;
        }
    }
}

/*
./client 35859 "👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_��_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!./client6701👋_🆕_❤️_🆓_⚒️_=_Welcome_to_your_new_favorite_free_tool!2wqw1./client6701👋_w"

*/