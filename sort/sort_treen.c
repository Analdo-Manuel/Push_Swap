/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_treen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:25:36 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/25 13:55:59 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	smool_index_or(t_pilha *stack_b)
{
	t_no	*tmp;
	int		smool;
	int		i;
	int		r;

	tmp = stack_b->no;
	smool = tmp->num;
	i = 1;
	r = 0;
	while (tmp->next)
	{
		if (smool > tmp->next->num)
		{
			smool = tmp->next->num;
			if (i <= (stack_b->size / 2))
			{
				tmp->move1 = 1;
				r = i;
			}
			else
			{
				tmp->move1 = 0;
				r = stack_b->size - i;
			}
		}
		i++;
		tmp = tmp->next;
	}
	return (r);
}

void    orden_a(t_pilha *stack_a)
{
    t_no    *a;
    int     i;

    i = smool_index_or(stack_a);
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
