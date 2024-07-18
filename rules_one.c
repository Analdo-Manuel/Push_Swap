/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:13:07 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/17 07:51:46 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_sa(t_pilha *stack_a)
{
	if (!stack_a || !stack_a->no)
		return ;
	swap_stacks(stack_a);
	write(1, "sa\n", 3);
	stack_a->count++;
}

void	swap_sb(t_pilha *stack_b)
{
	if (!stack_b || !stack_b->no)
		return ;
	swap_stacks(stack_b);
	write(1, "sb\n", 3);
	stack_b->count++;
}

void	swap_ss(t_pilha *stack_a, t_pilha *stack_b)
{
	if (!stack_a || !stack_a->no || !stack_b || !stack_b->no)
		return ;
	swap_sa(stack_a);
	swap_sb(stack_b);
	write(1, "ss\n", 3);
	stack_a->count++;
}

void	swap_pa(t_pilha *stack_a, t_pilha *stack_b)
{
	if (stack_b->size == 0)
		return ;
	ft_push(stack_a, stack_b->no->num);
	ft_pop(stack_b);
	write(1, "pa\n", 3);
	stack_a->count++;
}

void	swap_pb(t_pilha *stack_a, t_pilha *stack_b)
{
	if (stack_a->size == 0)
		return ;
	ft_push(stack_b, stack_a->no->num);
	ft_pop(stack_a);
	write(1, "pb\n", 3);
	stack_a->count++;
}
