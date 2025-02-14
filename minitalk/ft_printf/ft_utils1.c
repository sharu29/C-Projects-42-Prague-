/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-25 15:12:51 by snataraj          #+#    #+#             */
/*   Updated: 2024-06-25 15:12:51 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// print number

void	ft_number(int n, int *len)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		print_char('-', len);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_number(nb / 10, len);
		ft_number(nb % 10, len);
	}
	else
	{
		print_char(nb + '0', len);
	}
}

// hexadecimal

void	ft_hex(unsigned int n, int *len, char x)
{
	char	str[25];
	char	*base;
	int		i;

	i = 0;
	if (x == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
	{
		print_char('0', len);
		return ;
	}
	while (n != 0)
	{
		str[i] = base[n % 16];
		n /= 16;
		i++;
	}
	while (i--)
		print_char(str[i], len);
}

// unsigned int

void	ft_unsigned_int(unsigned int u, int *len)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, len);
	print_char(u % 10 + '0', len);
}

// pointer

void	ft_pointer(size_t pt, int *len)
{
	char	str[25];
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (pt == 0)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*len) += 2;
	while (pt != 0)
	{
		str[i] = base[pt % 16];
		pt /= 16;
		i++;
	}
	while (i--)
		print_char(str[i], len);
}
