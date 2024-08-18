/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 14:07:33 by snataraj          #+#    #+#             */
/*   Updated: 2024-06-21 14:07:33 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	print_char(char c, int *len);
void	print_string(char *args, int *len);
void	ft_number(int n, int *len);
void	ft_hex(unsigned int n, int *len, char x);
void	ft_unsigned_int(unsigned int u, int *len);
void	ft_pointer(size_t pt, int *len);
int		ft_printf(const char *format, ...);
void	print_format(char s, va_list *args, int *len, int *i);

#endif