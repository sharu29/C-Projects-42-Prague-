/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:56:12 by snataraj          #+#    #+#             */
/*   Updated: 2025/01/10 16:17:50 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack_node **a, char **av, bool flag_ac2)
{
	long	nb;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_ac2);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_free(a, av, flag_ac2);
		if (error_rep(*a, (int)nb))
			error_free(a, av, flag_ac2);
		append_node(a, (int)nb);
		i++;
	}
	if (flag_ac2)
		free_matrix(av);
}

static long	ft_atol(const char *ptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((ptr[i] == ' ') || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(ptr[i]))
	{
		res = (res * 10) + (ptr[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_isdigit(int s)
{
	return (s >= '0' && s <= '9');
}
