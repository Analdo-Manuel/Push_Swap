/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:00:48 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/05 02:45:46 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	test_two(t_pilha *stack_a, char **av, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		av = ft_split(av[1]);
		ac = ft_strlen(av);
		i = 1;
	}
	if (insert_valuer(stack_a, av, ac, i))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (0);
}
