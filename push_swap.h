/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:51:29 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 15:31:28 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_double_llst
{
	int						data;
	int						index;
	struct s_double_llst	*next;
	struct s_double_llst	*prev;
}t_double_llst;

typedef struct s_stack
{	
	size_t					cnt;
	struct s_double_llst	*top;
	struct s_double_llst	*bottom;
}t_stack;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
}t_stacks;

void				execute_command_with_print(t_stacks *stacks,
						char *command_name,
						void (*f)(t_stacks *));

void				radix_sort_base3(t_stacks *stacks);

void				sort_2_elem(t_stacks *stacks);
void				sort_3_elem(t_stacks *stacks);

t_double_llst		*init_node(int _data);
t_stack				*init_stack(void);
t_stacks			*init_stacks(int argc, char **argv);

void				find_input_error(char	*input);
void				insert_index_list(t_list **index_list,
						t_double_llst *new_node);

t_double_llst		*pop(t_stack *stack);
t_double_llst		*pop_bottom(t_stack *stack);
void				push(t_stack *stack, t_double_llst *node);
void				push_bottom(t_stack *stack, t_double_llst *node);

void				pa(t_stacks *stacks);
void				pb(t_stacks *stacks);

void				swap(t_stack *stack);
void				sa(t_stacks *stacks);
void				sb(t_stacks *stacks);
void				ss(t_stacks *stacks);

void				rotate(t_stack *stack);
void				ra(t_stacks *stacks);
void				rb(t_stacks *stacks);
void				rr(t_stacks *stacks);

void				reverse_rotate(t_stack *stack);
void				rra(t_stacks *stacks);
void				rrb(t_stacks *stacks);
void				rrr(t_stacks *stacks);
#endif