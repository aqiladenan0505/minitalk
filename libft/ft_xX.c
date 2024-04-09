/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:19:00 by aadenan           #+#    #+#             */
/*   Updated: 2023/12/29 14:03:27 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_subhex(unsigned int num, const char letter)
{
	if (num >= 16)
	{
		ft_subhex(num / 16, letter);
		ft_subhex(num % 16, letter);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (letter == 'x')
				ft_putchar(num - 10 + 'a');
			if (letter == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_puthex(unsigned int num, const char letter)
{
	int	len;

	len = 0;
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_subhex(num, letter);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_proxy(int n, char *num, unsigned int len)
{
	num[len] = '\0';
	num[0] = '-';
	if (n == -2147483648)
	{
		num[--len] = '8';
		n /= 10;
	}
	n = -n;
	return (n);
}
