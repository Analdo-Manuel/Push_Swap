/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicuma <kicuma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:37:23 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/21 21:13:35 by kicuma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A funcao verifica se existe algum caracter diferente de 0 ~ 9 ou -
static int	check_av(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
			return (1);
		if (str[i] == '-' && str[i + 1] == '-')
			return (1);
		i++;
	}
	return (0);
}

// A funcao verifica se existe algum numero repetido
static int	check_repeated(t_no *stack_a, int num)
{
	t_no	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->num == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_insert_valuer(t_pilha *p, char **av, int ac, int v)
{
	int	i;

	i = ac;
	while (--i > 0)
		if (check_av(av[i]))
			return (1);
	i = ac;
	while (--i > 0)
	{
		if (check_repeated(p->no, ft_atoi(av[i])))
			return (1);
		ft_push(p, ft_atoi(av[i]));
	}
	if (v == 1)
	{
		i = ac;
		while (av[i])
			free(av[i--]);
		free(av);
	}
	return (0);
}
