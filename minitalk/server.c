/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-11 11:18:30 by snataraj          #+#    #+#             */
/*   Updated: 2024-09-11 11:18:30 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	from_bit(int sig)
{
	int			bit;
	static int	i;
	static int	msg;

	if (sig == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	msg += ((bit & 1) << i);
	i++;
	if (i == 8)
	{
		if (msg == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", msg);
		msg = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome to the server\n");
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, from_bit);
		signal(SIGUSR1, from_bit);
		pause();
	}
	write(1, "\n", 1);
	return (0);
}
