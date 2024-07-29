/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:08:20 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/28 21:32:31 by almanuel         ###   ########.fr       */
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

static int	big_index(t_no *a, t_pilha *stack_b)
{
	t_no	*tmp;
	int		max;

	tmp = stack_b->no;
	max = tmp->num;
	return (r_big_index(stack_b, a, tmp, max));
}

static void	check_loop(t_pilha *stack_b, t_no *a, t_no *b, int *k, int *j)
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
	int		k;

	a = stack_a->no;
	while (a)
	{
		b = stack_b->no;
		j = init(b, a->num);
		k = 1;
		check_loop(stack_b, a, b, &k, &j);
		if (k == 1)
			a->target = big_index(a, stack_b);
		a = a->next;
	}
}
