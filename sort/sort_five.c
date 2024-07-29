/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:01:33 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/28 23:06:15 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	big_number(t_no *stack)
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

static int	loop_small(t_pilha *st_a, t_no *b, t_no *tmp, int small)
{
	int	r;
	int	i;

	r = 0;
	i = 1;
	while (tmp->next)
	{
		if (small > tmp->next->num)
		{
			small = tmp->next->num;
			if (i <= (st_a->size / 2))
			{
				b->move = 1;
				r = i;
			}
			else
			{
				b->move = 0;
				r = st_a->size - i;
			}
		}
		i++;
		tmp = tmp->next;
	}
	return (r);
}

static int	small_index(t_no *b, t_pilha *st_a)
{
	t_no	*tmp;
	int		small;

	tmp = st_a->no;
	small = tmp->num;
	return (loop_small(st_a, b, tmp, small));
}

static void	loop_target(t_pilha *st_a, t_no *a, t_no *b, int *k, int j)
{
	int	i;

	i = 0;
	while (a)
	{
		if (b->num < a->num && j > (a->num - b->num))
		{
			j = a->num - b->num;
			if (i <= (st_a->size / 2))
			{
				b->target = i;
				b->move = 1;
				*k = 0;
			}
			else
			{
				b->target = st_a->size - i;
				b->move = 0;
				*k = 0;
			}
		}
		i++;
		a = a->next;
	}
}

void	target_b(t_pilha *stack_b, t_pilha *stack_a)
{
	t_no	*a;
	t_no	*b;
	int		j;
	int		k;

	b = stack_b->no;
	a = stack_a->no;
	k = 1;
	j = big_number(a);
	loop_target(stack_a, a, b, &k, j);
	if (k == 1)
		b->target = small_index(b, stack_a);
}
