/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:52:48 by asoudani          #+#    #+#             */
/*   Updated: 2024/12/21 21:11:30 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putnbr(int nb)
{
	long	i;
	long	n;

	i = 1;
	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (i * 10 <= n)
	{
		i *= 10;
	}
	while (i > 0)
	{
		ft_putchar((n / i) + '0');
		n %= i;
		i /= 10;
	}
}
