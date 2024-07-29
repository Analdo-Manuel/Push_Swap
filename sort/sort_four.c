/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:05:46 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/28 22:45:01 by almanuel         ###   ########.fr       */
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

static void	op_doubles(t_pilha *a, t_pilha *b, t_no *t, int *x, int *y)
{
	int	i;
	int	j;

	i = *x;
	j = *y;
	if (t->move == t->move1)
	{
		if (t->move == 0)
		{
			while (i && j)
			{
				swap_rr(a, b);
				i--;
				j--;
			}
		}
		else
		{
			while (i && j)
			{
				swap_rrr(a, b);
				i--;
				j--;
			}
		}
	}
	*x = i;
	*y = j;
}

// Mandar todos os valorer da stack_a para stack_b
void	sort_stack_bo(t_pilha *stack_a, t_pilha *stack_b)
{
	int		i;
	int		j;
	t_no	*a;

	a = stack_a->no;
	a = custo_smoll(a);
	i = a->target;
	j = a->op;
	op_doubles(stack_a, stack_b, a, &i, &j);
	sort_stack_b(stack_a, stack_b, a, i, j);
}

void	sort_b(t_pilha *stack_a, t_pilha *stack_b)
{
	t_no	*b;
	int		i;

	while (stack_b->no)
	{
		target_b(stack_b, stack_a);
		b = stack_b->no;
		i = b->target;
		if (b->move == 1)
			while (i--)
				swap_ra(stack_a);
		else
			while (i--)
				swap_rra(stack_a);
		swap_pa(stack_a, stack_b);
	}
}
