/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:35:17 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/19 17:16:56 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verficador(t_no *stack_a)
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

static void	verficador3(t_pilha *stack_a)
{
	t_no	*tmp;

	tmp = stack_a->no;
	if (tmp->num > tmp->next->num && tmp->num > tmp->next->next->num)
		swap_ra(stack_a);
	else if (tmp->num < tmp->next->num && tmp->next->num > tmp->next->next->num)
		swap_rra(stack_a);
	tmp = stack_a->no;
	if (tmp->num > tmp->next->num)
		swap_sa(stack_a);
}

static void	verficador4(t_pilha *stack_a, t_pilha *stack_b)
{
	int		i;
	int		small;
	t_no	*tmp;

	i = 1;
	tmp = stack_a->no;
	small = tmp->num;
	while (tmp)
	{
		if (tmp->num < small)
			small = tmp->num;
		tmp = tmp->next;
	}
	tmp = stack_a->no;
	while (tmp)
	{
		if (small == tmp->num)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i == 4)
		swap_rra(stack_a);
	else
		while (--i)
			swap_ra(stack_a);
	swap_pb(stack_a, stack_b);
	verficador3(stack_a);
	swap_pa(stack_a, stack_b);
}

static void	verficador5(t_pilha *stack_a, t_pilha *stack_b)
{
	int		i;
	int		small;
	t_no	*tmp;

	i = 1;
	tmp = stack_a->no;
	small = tmp->num;
	while (tmp)
	{
		if (tmp->num < small)
			small = tmp->num;
		tmp = tmp->next;
	}
	tmp = stack_a->no;
	while (tmp)
	{
		if (small == tmp->num)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i == 5)
		swap_rra(stack_a);
	else
		while (--i)
			swap_ra(stack_a);
	swap_pb(stack_a, stack_b);
	verficador4(stack_a, stack_b);
	swap_pa(stack_a, stack_b);
}
void	check(t_pilha *stack_a, t_pilha *stack_b)
{
	if (verficador(stack_a->no))
	{
		if (stack_a->size == 2)
			swap_sa(stack_a);
		if (stack_a->size == 3)
			verficador3(stack_a);
		if (stack_a->size == 4)
			verficador4(stack_a, stack_b);
		if (stack_a->size == 5)
			verficador5(stack_a, stack_b);
	}
}
