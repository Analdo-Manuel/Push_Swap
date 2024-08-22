/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:37:56 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/22 16:24:16 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_no
{
	int			num;
	int			target;
	int			operation;
	int			custo;
	int			up;
	int			low;
	int			conf;
	struct s_no	*next;
}				t_no;
typedef struct s_pilha
{
	t_no		*no;
	int			size;
	int			count;
}				t_pilha;

void	new_stack(t_pilha *P);
void	ft_push(t_pilha *P, int dado);
void	ft_pop(t_pilha *P);
void	swap_stacks(t_pilha *P);

void	sa(t_pilha *stack_a);
void	sb(t_pilha *stack_b);
void	ss(t_pilha *stack_a, t_pilha *stack_b);
void	pa(t_pilha *stack_a, t_pilha *stack_b);
void	pb(t_pilha *stack_a, t_pilha *stack_b);
void	ra(t_pilha *stack_a);
void	rb(t_pilha *stack_b);
void	rr(t_pilha *stack_a, t_pilha *stack_b);
void	rra(t_pilha *stack_a);
void	rrb(t_pilha *stack_b);
void	rrr(t_pilha *stack_a, t_pilha *stack_b);
void	sort_all(t_pilha *stack_a, t_pilha *stack_b);

void	target(t_pilha *stack_a, t_pilha *stack_b);
void	operation_number(t_pilha *stack_a);
void	custo(t_pilha *stack_a);
void	operation_simple(t_pilha *stack_a, t_pilha *stack_b, t_no *a);
void	orden_b(t_pilha *stack_b);
void	small_no(t_pilha *stack_a);
void	sort_stack_a(t_pilha *stack_a, t_pilha *stack_b);
void	sort_stack_b(t_pilha *stack_a, t_pilha *stack_b);
void	target_a(t_pilha *stack_b, t_pilha *stack_a);
void	test_two(t_pilha *stack_a, char **av, int ac);

int		insert_valuer(t_pilha *P, char **av, int ac, int i);

char	**ft_split(char *str);
#endif
