/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:18:52 by kicuma            #+#    #+#             */
/*   Updated: 2024/07/25 16:37:00 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operacoes_a(t_pilha *stack_a)
{
	t_no	*a;
	int		i;

	a = stack_a->no;
	i = 0;
	while (a)
	{
		if (i <= (stack_a->size / 2) || stack_a->size == 2)
		{
			a->op = i;
			a->move1 = 0;
		}
		else
		{
			a->op = stack_a->size - i;
			a->move1 = 1;
		}
		i++;
		a = a->next;
	}
}

void	custo(t_pilha *stack_a)
{
	t_no	*a;

	a = stack_a->no;
	while (a)
	{
		if (a->move == a->move1)
		{
			if (a->target == a->op)
				a->custo = (a->target + a->op) / 2;
			else
			{
				if (a->target > a->op)
					a->custo = a->target;
				else
					a->custo = a->op;
			}
		}
		else
			a->custo = a->target + a->op;
		a = a->next;
	}
}

void	sort_stack_b(t_pilha *stack_a, t_pilha *stack_b, t_no *a, int i, int j)
{
	if (i > 0)
	{
		if (a->move == 0)
			while (i--)
				swap_rb(stack_b);
		else
			while (i--)
				swap_rrb(stack_b);
	}	
	if (j > 0)
	{
		if (a->move1 == 0)
			while (j--)
				swap_ra(stack_a);
		else
			while (j--)
				swap_rra(stack_a);
	}
	swap_pb(stack_a, stack_b);
}
