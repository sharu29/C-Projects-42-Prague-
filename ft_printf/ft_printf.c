/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 14:07:58 by snataraj          #+#    #+#             */
/*   Updated: 2024-06-21 14:07:58 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_format(char s, va_list *args, int *len, int *i)
{
	if (s == 'c')
		print_char(va_arg(*args, int), len);
	else if (s == 's')
		print_string(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (s == 'x')
		ft_hex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hex(va_arg(*args, unsigned int), len, 'X');
	else if (s == '%')
		print_char('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			print_format(format[++i], &args, &len, &i);
		else
			print_char((char)format[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}

/* int	main(void)
{
	int count;

	// ft_printf("hello my name is Laura and i'm 23 years old\n");
	count = ft_printf("hello my name is %s and i'm %d years old\n", "Laura",
			22);
	ft_printf("Total number of characters written are %d\n", count);
	// ft_putstr("1234");
	count = ft_printf("%p %p",0,0);
	ft_printf("Total number of characters written are %d\n", count);
} */