/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_treen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:25:36 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/05 03:44:51 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	loop_small(t_pilha *stack_a, t_no *tmp, int small)
{
	int	i;
	int	r;

	i = 1;
	r = 0;
	while (tmp->next)
	{
		if (small > tmp->next->num)
		{
			small = tmp->next->num;
			if (i <= (stack_a->size / 2))
			{
				tmp->low = 1;
				r = i;
			}
			else
			{
				tmp->low = 0;
				r = stack_a->size - i;
			}
		}
		i++;
		tmp = tmp->next;
	}
	return (r);
}

static int	small_index_or(t_pilha *stack_a)
{
	t_no	*tmp;
	int		small;

	tmp = stack_a->no;
	small = tmp->num;
	return (loop_small(stack_a, tmp, small));
}

void	small_no(t_pilha *stack_a)
{
	t_no	*a;
	int		i;

	i = small_index_or(stack_a);
	a = stack_a->no;
	while (i && (a->low == 1))
	{
		ra(stack_a);
		i--;
	}
	while (i && (a->low == 0))
	{
		rra(stack_a);
		i--;
	}
}
