/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:14:07 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/05 03:45:48 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pilha *stack_a)
{
	t_no	*tmp1;
	t_no	*tmp2;

	if (stack_a->size == 0 || !stack_a->no->next)
		return ;
	tmp1 = stack_a->no;
	tmp2 = stack_a->no;
	while (tmp1->next)
		tmp1 = tmp1->next;
	stack_a->no = tmp2->next;
	tmp2->next = NULL;
	tmp1->next = tmp2;
	write(1, "ra\n", 3);
	stack_a->count++;
}

void	rb(t_pilha *stack_b)
{
	t_no	*tmp1;
	t_no	*tmp2;

	if (!stack_b || !stack_b->no->next)
		return ;
	tmp1 = stack_b->no;
	tmp2 = stack_b->no;
	while (tmp1->next)
		tmp1 = tmp1->next;
	stack_b->no = tmp2->next;
	tmp2->next = NULL;
	tmp1->next = tmp2;
	write(1, "rb\n", 3);
	stack_b->count++;
}

void	rr(t_pilha *stack_a, t_pilha *stack_b)
{
	t_no	*tmp1;
	t_no	*tmp2;

	if (!stack_a || !stack_a->no || !stack_b || !stack_b->no)
		return ;
	tmp1 = stack_a->no;
	tmp2 = stack_a->no;
	while (tmp1->next)
		tmp1 = tmp1->next;
	stack_a->no = tmp2->next;
	tmp2->next = NULL;
	tmp1->next = tmp2;
	tmp1 = stack_b->no;
	tmp2 = stack_b->no;
	while (tmp1->next)
		tmp1 = tmp1->next;
	stack_b->no = tmp2->next;
	tmp2->next = NULL;
	tmp1->next = tmp2;
	write(1, "rr\n", 3);
	stack_a->count++;
}

void	rra(t_pilha *stack_a)
{
	t_no	*tmp1;
	t_no	*tmp2;

	if (!stack_a || !stack_a->no)
		return ;
	tmp1 = stack_a->no;
	while (tmp1->next)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = NULL;
	tmp1->next = stack_a->no;
	stack_a->no = tmp1;
	write(1, "rra\n", 4);
	stack_a->count++;
}

void	rrb(t_pilha *stack_b)
{
	t_no	*tmp1;
	t_no	*tmp2;

	if (!stack_b || !stack_b->no)
		return ;
	tmp1 = stack_b->no;
	while (tmp1->next)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = NULL;
	tmp1->next = stack_b->no;
	stack_b->no = tmp1;
	write(1, "rrb\n", 4);
	stack_b->count++;
}
