/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:37:05 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/19 17:16:58 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pilha	stack_a;
	t_pilha	stack_b;

	if (ac > 1)
	{
		ft_new_pilha(&stack_a);
		ft_new_pilha(&stack_b);

		if (ft_test_one(&stack_a, av, ac))
				return (0);
		swap_pb(&stack_a, &stack_b);
		swap_pb(&stack_a, &stack_b);
		swap_pb(&stack_a, &stack_b);
		swap_pb(&stack_a, &stack_b);
		swap_pb(&stack_a, &stack_b);
		target(&stack_a, &stack_b);
		//check(&stack_a, &stack_b);
		printf("TOTAL DE OPERACOES: %d\nMAIOR NUM: %d\n", stack_a.count, big_number(stack_a.no));
		while (stack_a.no)
		{
			printf("valo: %d, target: %d\n", stack_a.no->num, stack_a.no->target);
			ft_pop(&stack_a);
		}
		printf("------------ VALOR DE STACK_B ------------\n");
		while (stack_b.no)
		{
			printf("%d\n", stack_b.no->num);
			ft_pop(&stack_b);
		}
		free(stack_a.no);
		free(stack_b.no);
		
	}
	exit(0);
	return (0);
}
