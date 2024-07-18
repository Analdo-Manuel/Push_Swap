/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:13:39 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/17 07:53:51 by almanuel         ###   ########.fr       */
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

void	swap_rrr(t_pilha *stack_a, t_pilha *stack_b)
{
	if (!(stack_a || stack_a->no || stack_b || stack_b->no))
		return ;
	swap_rra(stack_a);
	swap_rrb(stack_b);
	write(1, "rrr\n", 4);
	stack_a->count++;
}
