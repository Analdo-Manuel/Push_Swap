/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:05:46 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/25 14:02:42 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		smool_index(t_no *a, t_pilha *stack_b)
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
				a->move = 1;
				r = i;
			}
			else
			{
				a->move = 0;
				r = stack_b->size - i;
			}
		}
		i++;
		tmp = tmp->next;
	}
	return (r);
}

void    target_b(t_pilha *stack_b, t_pilha *stack_a)
{
	t_no	*a;
	t_no	*b;
	int		i;
   	int		j;
	int		k;

	b = stack_b->no;
	if (b)
	{
        a = stack_a->no;
		i = 0;
        j = big_number(a);
        k = 0;
        while (a)
        {
            if (b->num < a->num && j > (a->num - b->num))
            {
                j = a->num - b->num;
                if (i <= (stack_a->size / 2))
                {
                    b->target = i;
                    b->move = 1;
                    k = 1;
                }
                else
                {
                    b->target = stack_a->size - i;
                    b->move = 0;
                    k = 1;
                }
            }
            i++;
            a = a->next;
        }
        if (k == 0)
        {
            b->target = smool_index(b, stack_a);
        }
	}
}

static t_no		*custo_smoll(t_no *a)
{
	t_no 	*tmp;

	tmp = a;
	while (a->next)
	{
		a = a->next;
		if (tmp->custo > a->custo)
			tmp = a;
	}
	return (tmp);
}

// Mandar todos os valorer da stack_a para stack_b
void	sort_stack_bo(t_pilha *stack_a, t_pilha *stack_b)
{
	int		i;
	int		j;
	t_no	*a;

	a = stack_a->no;
	a = custo_smoll(a);
	i = a->target;
	j = a->op;
	if (a->move == a->move1)
	{
		if (a->move == 0)
		{
			while (i && j)
			{
				swap_rr(stack_a, stack_b);
				i--;
				j--;
			}
		}
		else
		{
			while (i && j)
			{
				swap_rrr(stack_a, stack_b);
				i--;
				j--;
			}
		}
	}
	sort_stack_b(stack_a, stack_b, a, i, j);
}

void    sort_b(t_pilha *stack_a, t_pilha *stack_b)
{
    t_no    *b;
    int     i;

    while (stack_b->no)
    {
        target_b(stack_b, stack_a);
        b = stack_b->no;
        i = b->target;
        if (b->move == 1)
            while (i--)
                swap_ra(stack_a);
        else
            while (i--)
            {
                swap_rra(stack_a);
            }
        swap_pa(stack_a, stack_b);
    }
}
