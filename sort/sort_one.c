/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:08:20 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/25 13:49:25 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	big_number(t_no *stack)
{
	int		max;
	t_no	*tmp;

	tmp = stack;
	max = tmp->num;
	while (tmp)
	{
		if (max < tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

static int		big_index(t_no *a, t_pilha *stack_b)
{
	t_no	*tmp;
	int		max;
	int		i;
	int		r;

	tmp = stack_b->no;
	max = tmp->num;
	i = 1;
	r = 0;
	while (tmp->next)
	{
		if (max < tmp->next->num)
		{
			max = tmp->next->num;
			if (i <= (stack_b->size / 2) || stack_b->size == 2)
			{
				a->move = 0;
				r = i;
			}
			else
			{
				a->move = 1;
				r = stack_b->size - i;
			}
		}
		i++;
		tmp = tmp->next;
	}
	return (r);
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

void	check_loop(t_pilha *stack_b, t_no *a, t_no *b, int i, int *j, int *k)
{
	if (a->num > b->num && *j >= a->num - b->num)
	{
		if (i <= (stack_b->size / 2) || stack_b->size == 2)
		{
			a->target = i;
			*j = a->num - b->num;
			*k = 0;
			a->move = 0;
		}
		else
		{
			a->target = stack_b->size - i;
			*j = a->num - b->num;
			*k = 0;
			a->move = 1;
		}
	}
}

void	target(t_pilha *stack_a, t_pilha *stack_b)
{
	t_no	*a;
	t_no	*b;
	int		i;
	int		j;
	int		k;

	a = stack_a->no;
	while (a)
	{
		b = stack_b->no;
		j = init(b, a->num);
		i = 0;
		k = 1;
		while (b)
		{
			check_loop(stack_b, a, b, i, &j, &k);
			b = b->next;
			i++;
		}
		if (k == 1)
			a->target = big_index(a, stack_b);
		a = a->next;
	}
}
