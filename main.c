/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:37:05 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/25 16:45:14 by almanuel         ###   ########.fr       */
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
		check(&stack_a, &stack_b);
		//printf("TOTAL DE OPERACOES: %d\n", stack_a.count + stack_b.count);
		while (stack_a.no)
		{
		//	printf("Op: %d || Valor: %d || Target: %d || Custo: %d\n",
		//		stack_a.no->op, stack_a.no->num, stack_a.no->target,
		//		stack_a.no->custo);
			ft_pop(&stack_a);
		}
		//printf("---------- VALOR DA PILHA B ---------\n");
		while (stack_b.no)
		{
		//	printf("Valor: %d\n", stack_b.no->num);
			ft_pop(&stack_b);
		}
		free(stack_a.no);
		free(stack_b.no);
	}
	exit(0);
	return (0);
}
