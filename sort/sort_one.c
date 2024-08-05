/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:08:20 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/05 02:44:06 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	r_big_index(t_pilha *stack_b, t_no *a, t_no *tmp, int max)
{
	int	r;
	int	i;

	i = 1;
	r = 0;
	while (tmp->next)
	{
		if (max < tmp->next->num)
		{
			max = tmp->next->num;
			if (i <= (stack_b->size / 2) || stack_b->size == 2)
			{
				a->up = 0;
				r = i;
			}
			else
			{
				a->up = 1;
				r = stack_b->size - i;
			}
		}
		i++;
		tmp = tmp->next;
	}
	return (r);
}

static int	big_index(t_no *a, t_pilha *stack_b)
{
	t_no	*tmp;
	int		max;

	tmp = stack_b->no;
	max = tmp->num;
	return (r_big_index(stack_b, a, tmp, max));
}

static void	target_value(t_pilha *stack_b, t_no *a, t_no *b, int *j)
{
	int	i;

	i = 0;
	while (b)
	{
		if (a->num > b->num && *j >= a->num - b->num)
		{
			if (i <= (stack_b->size / 2) || stack_b->size == 2)
			{
				a->target = i;
				*j = a->num - b->num;
				a->conf = 1;
				a->up = 0;
			}
			else
			{
				a->target = stack_b->size - i;
				*j = a->num - b->num;
				a->conf = 1;
				a->up = 1;
			}
		}
		i++;
		b = b->next;
	}
}

static int	init(t_no *stack_b, int num)
{
	t_no	*b;

	b = stack_b;
	while (b)
	{
		if (num > b->num)
			return (num - b->num);
		b = b->next;
	}
	return (0);
}

void	target(t_pilha *stack_a, t_pilha *stack_b)
{
	t_no	*a;
	t_no	*b;
	int		j;

	a = stack_a->no;
	while (a)
	{
		b = stack_b->no;
		j = init(b, a->num);
		target_value(stack_b, a, b, &j);
		if (a->conf == 0)
			a->target = big_index(a, stack_b);
		a = a->next;
	}
}
