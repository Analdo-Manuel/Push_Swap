/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:18:52 by kicuma            #+#    #+#             */
/*   Updated: 2024/08/22 15:07:58 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_number(t_pilha *stack_a)
{
	t_no	*a;
	int		i;

	a = stack_a->no;
	i = 0;
	while (a)
	{
		if (i <= (stack_a->size / 2) || stack_a->size == 2)
		{
			a->operation = i;
			a->low = 0;
		}
		else
		{
			a->operation = stack_a->size - i;
			a->low = 1;
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
		if (a->up == a->low)
		{
			if (a->target == a->operation)
				a->custo = (a->target + a->operation) / 2;
			else
			{
				if (a->target > a->operation)
					a->custo = a->target;
				else
					a->custo = a->operation;
			}
		}
		else
			a->custo = a->target + a->operation;
		a = a->next;
	}
}

void	operation_simple(t_pilha *stack_a, t_pilha *stack_b, t_no *a)
{
	int	i;
	int	j;

	i = a->target;
	j = a->operation;
	if (i > 0)
	{
		if (a->up == 0)
			while (i--)
				rb(stack_b);
		else
			while (i--)
				rrb(stack_b);
	}
	if (j > 0)
	{
		if (a->low == 0)
			while (j--)
				ra(stack_a);
		else
			while (j--)
				rra(stack_a);
	}
	pb(stack_a, stack_b);
}
