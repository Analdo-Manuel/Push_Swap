/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 02:47:56 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/22 13:54:30 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_pilha stack_a, t_pilha stack_b)
{
	while (stack_a.no)
		ft_pop(&stack_a);
	while (stack_b.no)
		ft_pop(&stack_b);
	free(stack_a.no);
	free(stack_b.no);
}

static	void	checker(char **av)
{
	int	i;

	i = 0;
	if (av[1][0] == '\0' || (av[1][0] == '-'
			&& (av[1][1] < '0' || av[1][1] > '9')))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (av[1][i] == ' ' || av[1][i] == '\t')
		i++;
	if (av[1][i] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_pilha	stack_a;
	t_pilha	stack_b;

	if (ac > 1)
	{
		checker(av);
		new_stack(&stack_a);
		new_stack(&stack_b);
		test_two(&stack_a, av, ac);
		sort_all(&stack_a, &stack_b);
		free_stack(stack_a, stack_b);
	}
	exit(1);
	return (0);
}
