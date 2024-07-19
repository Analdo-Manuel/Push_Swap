/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:08:20 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/19 17:16:51 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int big_number(t_no *stack_a)
{
	int max;
	t_no *tmp = stack_a;

	max = tmp->num;
	while (tmp)
	{
		if (max < tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

static int	init(t_no *stack_b, int num)
{
	t_no	*tmp;

	tmp = stack_b;
	while (tmp)
	{
		if (num > tmp->num)
			return (num - tmp->num);
		tmp = tmp->next;
	}
	return (0);
}
// falta lidar com valores alvo zero - 21
void	target(t_pilha *stack_a, t_pilha *stack_b)
{
	t_no	*a;
	t_no	*b;
	int		i;
	int		tmp;

	a = stack_a->no;
	
	while (a)
	{
		b = stack_b->no;
		tmp = init(b, a->num);
		i = 0;
		while (b)
		{
			if (a->num > b->num)
			{
				
				if (tmp > a->num - b->num)
				{
					a->target = i;
					tmp = a->num - b->num;
				}
			}
			b = b->next;
			i++;
		}
		a = a->next;
	}
}
