/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analdo <analdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:47:56 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/08 16:55:06 by analdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pilha	stack_a;
	t_pilha	stack_b;

	if (ac > 1)
	{
		if (av[1][0] == '\0' || (av[1][0] == '-'
			&& (av[1][1] < '0' || av[1][1] > '9')))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		new_stack(&stack_a);
		new_stack(&stack_b);
		if (test_two(&stack_a, av, ac))
			return (0);
		sort_all(&stack_a, &stack_b);
		while (stack_a.no)
			ft_pop(&stack_a);
		while (stack_b.no)
			ft_pop(&stack_b);
		free(stack_a.no);
		free(stack_b.no);
	}
	exit(1);
	return (0);
}
