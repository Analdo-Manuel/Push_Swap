/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 08:27:43 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/19 17:16:57 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// inicializar uma pilha
void	ft_new_pilha(t_pilha *P)
{
	P->no = NULL;
	P->size = 0;
	P->count = 0;
}
// Empilhar ou criar uma pilha
void	ft_push(t_pilha *P, int dado)
{
	t_no	*swp;

	swp = (t_no *)malloc(sizeof(t_no));
	if (!swp)
		return ;
	swp->num = dado;
	swp->next = P->no;
	swp->operacao = 0;
	swp->target = 0;
	P->no = swp;
	P->size++;
}
// Desempilhar ou remover uma pilha
void	ft_pop(t_pilha *P)
{
	t_no	*rm;

	rm = P->no;
	P->no = rm->next;
	free(rm);
	P->size--;
}
// Split adaptado para ler o primeiro argumento
char	**ft_split(char *str)
{
	char	**p;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	p = (char **)malloc(sizeof(char *) * 7168);
	j = 1;
	p[0] = "0";
	while (str[i] > 32 && str[i] < 127)
	{
		k = 0;
		p[j] = (char *)malloc(sizeof(char) * 12);
		while (str[i] > 32 && str[i] < 127)
			p[j][k++] = str[i++];
		p[j][k] = '\0';
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		j++;
	}
	p[j] = NULL;
	return (p);
}