/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadenan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:36:20 by aadenan           #+#    #+#             */
/*   Updated: 2023/12/29 14:01:04 by aadenan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
int		ft_printf(const char *str, ...);
int		ft_format(va_list ap, const char letter);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putpercent(void);
int		ft_putunsigned(unsigned int n);
int		ft_putptr(unsigned long ptr);
int		ft_puthex(unsigned int num, const char letter);
int		ft_proxy(int n, char *num, unsigned int len);
void	ft_subptr(unsigned long num);
void	ft_subhex(unsigned int num, const char letter);
char	*ft_uitoa(unsigned int n, unsigned int len);
char	*ft_itoa(int n, unsigned int len);

#endif
