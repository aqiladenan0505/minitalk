/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:18:39 by aadenan           #+#    #+#             */
/*   Updated: 2023/12/29 14:03:16 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n, unsigned int len)
{
	char	*num;

	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	if (n == 0)
	{
		num[len] = '\0';
		num[0] = '0';
		return (num);
	}
	if (n < 0)
	{
		n = ft_proxy(n, num, len);
		if (n == 214748364)
			len = 10;
	}
	if (n != 214748364)
		num[len] = '\0';
	while (len-- && n != 0)
	{
		num[len] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

char	*ft_uitoa(unsigned int n, unsigned int len)
{
	char	*num;

	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	if (n == 0)
		num[0] = '0';
	num[len] = '\0';
	while (len-- && n != 0)
	{
		num[len] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

int	ft_putunsigned(unsigned int n)
{
	int					length;
	int					len;
	unsigned int		tmp;
	char				*num;

	length = 0;
	len = 0;
	tmp = n;
	if (n == 0)
		length = write(1, "0", 1);
	else
	{
		while (tmp != 0)
		{
			len++;
			tmp = tmp / 10;
		}
		num = ft_uitoa(n, len);
		length = ft_putstr(num);
		free(num);
	}
	return (length);
}

void	ft_subptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_subptr(num / 16);
		ft_subptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_putptr(unsigned long ptr)
{
	int	length;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	length = write(1, "0x", 2);
	ft_subptr(ptr);
	while (ptr != 0)
	{
		length++;
		ptr = ptr / 16;
	}
	return (length);
}
