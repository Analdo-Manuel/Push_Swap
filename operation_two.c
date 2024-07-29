/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:35:17 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/28 22:38:22 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verficador(t_no *stack_a)
{
	t_no	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	verficador3(t_pilha *stack_a)
{
	t_no	*tmp;

	if (stack_a->size == 2)
	{
		swap_sa(stack_a);
		return ;
	}
	tmp = stack_a->no;
	if (tmp->num > tmp->next->num
		&& tmp->num > tmp->next->next->num)
		swap_ra(stack_a);
	else if (tmp->num < tmp->next->num
		&& tmp->next->num > tmp->next->next->num)
		swap_rra(stack_a);
	tmp = stack_a->no;
	if (tmp->num > tmp->next->num)
		swap_sa(stack_a);
}

void	check(t_pilha *stack_a, t_pilha *stack_b)
{
	if (stack_a->size <= 3)
		verficador3(stack_a);
	else
	{
		swap_pb(stack_a, stack_b);
		swap_pb(stack_a, stack_b);
		while (stack_a->size > 3)
		{
			target(stack_a, stack_b);
			operacoes_a(stack_a);
			custo(stack_a);
			sort_stack_bo(stack_a, stack_b);
		}
		verficador3(stack_a);
		sort_b(stack_a, stack_b);
		while (verficador(stack_a->no))
			orden_a(stack_a);
	}
}
