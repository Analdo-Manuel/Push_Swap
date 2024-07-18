/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analise_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 08:00:48 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/18 09:02:02 by almanuel         ###   ########.fr       */
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

int	ft_test_one(t_pilha *stack_a, char **av, int ac)
{
    int i;

    i = 0;
	if (ac == 2)
    {
		av = ft_split(av[1]);
        ac = ft_strlen(av);
        i = 1;
    }
	if (ft_insert_valuer(stack_a, av, ac, i))
	{
		printf("Error\n");
		exit(-1);
	}
	return (0);
}
