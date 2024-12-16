/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:58:53 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/16 15:29:46 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
void    foo(int sig);
void    handle_signal(int sig);
void    foo(int sig);


#endif