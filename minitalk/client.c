/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-11 11:18:12 by snataraj          #+#    #+#             */
/*   Updated: 2024-09-11 11:18:12 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	to_bit(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 8)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift++;
			usleep(600);
		}
		i++;
	}
}

int	main(int ac, char **ag)
{
	int		pid;
	char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(ag[1]);
		str = ag[2];
		to_bit(pid, str, ft_strlen(str));
	}
	else
		ft_printf("\nBlank or more than 1 word\n");
}
