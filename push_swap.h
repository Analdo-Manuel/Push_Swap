/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:37:56 by almanuel          #+#    #+#             */
/*   Updated: 2024/07/18 10:19:56 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_no
{
	int			num;
	struct s_no	*next;
}				t_no;
typedef struct s_pilha
{
	t_no		*no;
	int			size;
	int			count;
}				t_pilha;

void			ft_new_pilha(t_pilha *P);
void			ft_push(t_pilha *P, int dado);
void			ft_pop(t_pilha *P);
void			swap_stacks(t_pilha *P);

void			swap_sa(t_pilha *stack_a);
void			swap_sb(t_pilha *stack_b);
void			swap_ss(t_pilha *stack_a, t_pilha *stack_b);
void			swap_pa(t_pilha *stack_a, t_pilha *stack_b);
void			swap_pb(t_pilha *stack_a, t_pilha *stack_b);
void			swap_ra(t_pilha *stack_a);
void			swap_rb(t_pilha *stack_b);
void			swap_rr(t_pilha *stack_a, t_pilha *stack_b);
void			swap_rra(t_pilha *stack_a);
void			swap_rrb(t_pilha *stack_b);
void			swap_rrr(t_pilha *stack_a, t_pilha *stack_b);
void			check(t_pilha *stack_a, t_pilha *stack_b);

int				ft_insert_valuer(t_pilha *P, char **av, int ac, int i);
int				ft_atoi(const char *str);
int				big_number(t_no *stack_a);
int				ft_test_one(t_pilha *stack_a, char **av, int ac);

char			**ft_split(char *str);
#endif
