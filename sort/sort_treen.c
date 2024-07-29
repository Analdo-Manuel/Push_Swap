/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_treen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:25:36 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/28 21:40:47 by almanuel         ###   ########.fr       */
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
				tmp->move1 = 1;
				r = i;
			}
			else
			{
				tmp->move1 = 0;
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

void	orden_a(t_pilha *stack_a)
{
	t_no	*a;
	int		i;

	i = small_index_or(stack_a);
	a = stack_a->no;
	while (i && (a->move1 == 1))
	{
		swap_ra(stack_a);
		i--;
	}
	while (i && (a->move1 == 0))
	{
		swap_rra(stack_a);
		i--;
	}
}
