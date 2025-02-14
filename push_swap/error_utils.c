/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:22:04 by snataraj          #+#    #+#             */
/*   Updated: 2025/01/10 16:17:37 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check repetition in stack

int	error_rep(t_stack_node *a, int nb)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

/*

check for syntax errors
 - if input string is a valid number
 - can start with +/-
 - followed by digits

*/
/* if functions
// checks if first char is a sign or digit, otherwise returns 1 (invalid)
// If first char is a sign, checks if the next char is a digit
// Checks if all subsequent chars are digits (0-9)
// If all checks pass, string is a valid number
 */
int	error_syntax(char *str_nb)
{
	if (!(*str_nb == '+' || *str_nb == '-' || ft_isdigit(*str_nb)))
		return (1);
	if ((*str_nb == '+' || *str_nb == '-') && (!ft_isdigit(*(str_nb + 1))))
		return (1);
	while (*++str_nb)
	{
		if (!ft_isdigit(*str_nb))
			return (1);
	}
	return (0);
}

/*
 to free the 2D array created by split function
 */

void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av - 1);
}

/*
free a stack
 */

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*cur;

	if (stack == NULL)
		return ;
	cur = *stack;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	*stack = NULL;
}

/*
free and print error message
 */

void	error_free(t_stack_node **a, char **av, bool flag_ac_2)
{
	free_stack(a);
	if (flag_ac_2)
		free_matrix(av);
	write(1, "Error\n", 6);
	exit(1);
}
