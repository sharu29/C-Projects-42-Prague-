/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:55:05 by snataraj          #+#    #+#             */
/*   Updated: 2025/01/10 16:11:36 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					cur_pos;
	int					f_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// split
// char					**ft_split(char const *s, char c);
char					**ft_split(char *str, char sep);

/* stack utils */

int						stack_len(t_stack_node *stack);
t_stack_node			*find_last_node(t_stack_node *head);
t_stack_node			*return_cheapest(t_stack_node *stack);
t_stack_node			*find_smallest(t_stack_node *stack);
void					append_node(t_stack_node **stack, int nb);

/* commands */

void					ra(t_stack_node **a, bool checker);
void					rb(t_stack_node **b, bool checker);
void					rr(t_stack_node **a, t_stack_node **b, bool checker);
void					rra(t_stack_node **a, bool checker);
void					rrb(t_stack_node **b, bool checker);
void					rrr(t_stack_node **a, t_stack_node **b, bool checker);
void					pa(t_stack_node **a, t_stack_node **b, bool checker);
void					pb(t_stack_node **b, t_stack_node **a, bool checker);
void					sa(t_stack_node **a, bool checker);
void					sb(t_stack_node **b, bool checker);
void					ss(t_stack_node **a, t_stack_node **b, bool checker);

/* stack init */

void					stack_init(t_stack_node **a, char **av, bool flag_ac2);
static long				ft_atol(const char *ptr);

/* error utils */

void					error_free(t_stack_node **a, char **av, bool flag_ac_2);
void					free_stack(t_stack_node **stack);
void					free_matrix(char **av);
int						error_syntax(char *str_nb);
int						error_rep(t_stack_node *a, int nb);
int						ft_isdigit(int s);

/* sorting algorithms - tiny_sort */

void					handle_three(t_stack_node **a);
void					handle_many(t_stack_node **a, t_stack_node **b);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_highest(t_stack_node *stack);
void					push_swap(t_stack_node **a, t_stack_node **b);
void					finish_rotation(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);

/* push_swap_init */

void					set_current_position(t_stack_node *stack);
static void				set_target_node(t_stack_node *a, t_stack_node *b);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);
void					init_nodes(t_stack_node *a, t_stack_node *b);

#endif
