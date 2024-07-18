/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:08:20 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/18 13:03:40 by almanuel         ###   ########.fr       */
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
int radix_digit(int num1, int num2)
{
    return (num1 / num2) % 10;
}