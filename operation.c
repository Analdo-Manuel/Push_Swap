/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analdo <analdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:35:17 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/08 16:55:03 by analdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker(t_no *stack_a)
{
	t_no	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	checker_3(t_pilha *stack_a)
{
	t_no	*tmp;

	if (stack_a->size == 2)
	{
		sa(stack_a);
		return ;
	}
	tmp = stack_a->no;
	if (tmp->num > tmp->next->num
		&& tmp->num > tmp->next->next->num)
		ra(stack_a);
	else if (tmp->num < tmp->next->num
		&& tmp->next->num > tmp->next->next->num)
		rra(stack_a);
	tmp = stack_a->no;
	if (tmp->num > tmp->next->num)
		sa(stack_a);
}

void	sort_all(t_pilha *stack_a, t_pilha *stack_b)
{
	if (checker(stack_a->no))
	{
		if (stack_a->size <= 3)
			checker_3(stack_a);
		else
		{
			pb(stack_a, stack_b);
			pb(stack_a, stack_b);
			while (stack_a->size > 3)
			{
				target(stack_a, stack_b);
				operation_number(stack_a);
				custo(stack_a);
				sort_stack_b(stack_a, stack_b);
			}
			checker_3(stack_a);
			sort_stack_a(stack_a, stack_b);
			while (checker(stack_a->no))
				small_no(stack_a);
		}
	}
}
