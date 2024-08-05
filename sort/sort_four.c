/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:05:46 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/05 04:35:38 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_no	*custo_smoll(t_no *a)
{
	t_no	*tmp;

	tmp = a;
	while (a->next)
	{
		a = a->next;
		if (tmp->custo > a->custo)
			tmp = a;
	}
	return (tmp);
}

static void	op_simultaneous(t_pilha *a, t_pilha *b, t_no *t)
{
	int	i;
	int	j;

	i = t->target;
	j = t->operation;
	if (t->up == 0)
	{
		while (i && j)
		{
			rr(a, b);
			i--;
			j--;
		}
	}
	else
	{
		while (i && j)
		{
			rrr(a, b);
			i--;
			j--;
		}
	}
	t->target = i;
	t->operation = j;
}

static void	operation_doubles(t_pilha *a, t_pilha *b, t_no *t)
{
	if (t->up == t->low)
	{
		op_simultaneous(a, b, t);
	}
}

void	sort_stack_b(t_pilha *stack_a, t_pilha *stack_b)
{
	t_no	*a;

	a = stack_a->no;
	a = custo_smoll(a);
	operation_doubles(stack_a, stack_b, a);
	operation_simple(stack_a, stack_b, a);
}

void	sort_stack_a(t_pilha *stack_a, t_pilha *stack_b)
{
	t_no	*b;
	int		i;

	while (stack_b->no)
	{
		target_a(stack_b, stack_a);
		b = stack_b->no;
		i = b->target;
		if (b->up == 1)
			while (i--)
				ra(stack_a);
		else
			while (i--)
				rra(stack_a);
		pa(stack_a, stack_b);
	}
}
