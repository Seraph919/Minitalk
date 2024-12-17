/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:28:32 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/16 22:18:37 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
void    foo(int sig);
int	    ft_atoi(const char *str);
void    handle_signal(int sig);
void    foo(int sig);


#endif