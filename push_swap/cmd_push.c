/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:09:29 by snataraj          #+#    #+#             */
/*   Updated: 2024/12/16 14:13:16 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
push a node to the top - src to dest
 */

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*to_push;

	if (*src == NULL)
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dest;
		to_push->next->prev = to_push;
		*dest = to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
