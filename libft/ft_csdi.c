/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:57:58 by aadenan           #+#    #+#             */
/*   Updated: 2023/12/29 14:03:01 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		len;
	int		tmp;
	char	*num;

	len = 0;
	tmp = n;
	if (tmp <= 0)
		len = 1;
	while (tmp != 0)
	{
		len++;
		tmp = tmp / 10;
	}
	num = ft_itoa(n, len);
	ft_putstr(num);
	free(num);
	return (len);
}

int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}
