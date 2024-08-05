/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:13:39 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/05 03:45:29 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stacks(t_pilha *P)
{
	t_no	*tmp1;
	t_no	*tmp2;

	if (P->size < 2 || !P)
		return ;
	tmp1 = P->no;
	tmp2 = tmp1->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	P->no = tmp2;
}

void	rrr(t_pilha *stack_a, t_pilha *stack_b)
{
	t_no	*tmp1;
	t_no	*tmp2;

	if (!(stack_a || stack_a->no || stack_b || stack_b->no))
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
	tmp1 = stack_b->no;
	while (tmp1->next)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = NULL;
	tmp1->next = stack_b->no;
	stack_b->no = tmp1;
	write(1, "rrr\n", 4);
	stack_a->count++;
}
