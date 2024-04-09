/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:57:14 by aadenan           #+#    #+#             */
/*   Updated: 2023/12/29 14:02:49 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list ap, const char letter)
{
	int	length;

	length = 0;
	if (letter == 'c')
		length = ft_putchar(va_arg(ap, int));
	else if (letter == 's')
		length = ft_putstr(va_arg(ap, char *));
	else if (letter == 'p')
		length = ft_putptr(va_arg(ap, unsigned long));
	else if (letter == 'd' || letter == 'i')
		length = ft_putnbr(va_arg(ap, int));
	else if (letter == 'u')
		length = ft_putunsigned(va_arg(ap, unsigned int));
	else if (letter == 'x' || letter == 'X')
		length = ft_puthex(va_arg(ap, unsigned int), letter);
	else if (letter == '%')
		length = ft_putpercent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	ap;

	i = 0;
	length = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			length += ft_format(ap, str[i + 1]);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (length);
}
/*
int main(void) {

	char c = 'A';
	printf("%c\n", c);
	ft_printf("%c\n", c);

	char *s = "Hey";
	printf("%s\n", s);
	ft_printf("%s\n", s);

	int num = 42;
	printf("%p\n", (void *)&num);
	ft_printf("%p\n", (void *)&num);
	printf("%u\n", num);
	ft_printf("%u\n", num);

	ft_printf("%d\n", -214748364);
	printf("%d\n", -214748364);

	int hex = 255;
	printf("%x\n", hex);
	ft_printf("%x\n", hex);

	printf("%%\n");
	ft_printf("%%\n");

	printf("\n%d\n", ft_printf("%d%%\n", atoi("50")));
	printf("\n%d\n", ft_printf("%d%%\n", atoi("50")));
	return 0;
}
*/
