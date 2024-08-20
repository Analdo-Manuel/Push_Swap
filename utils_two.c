/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:37:23 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/05 04:04:48 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// A funcao verifica se existe algum caracter diferente de 0 ~ 9 ou -
static	int	check_av(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	if (j > 10)
		return (1);
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
			return (1);
		if (str[i] == '-' && str[i + 1] == '-')
			return (1);
		if (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '-')
			return (1);
		i++;
	}
	return (0);
}

// A funcao verifica se existe algum numero repetido & max_int
static	int	check_repeated(t_no *stack_a, long num)
{
	t_no	*tmp;

	tmp = stack_a;
	if (num < -2147483648 || num > 2147483647)
		return (1);
	while (tmp)
	{
		if (tmp->num == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static	long	ft_atoi(const char *str)
{
	int	i;
	int	b;
	long	c;

	i = 0;
	b = 1;
	c = 0;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			b *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = c * 10 + (str[i] - '0');
		++i;
	}
	return (c * b);
}

int	insert_valuer(t_pilha *p, char **av, int ac, int v)
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
