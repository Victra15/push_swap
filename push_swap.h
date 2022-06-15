/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:51:29 by yolee             #+#    #+#             */
/*   Updated: 2022/06/16 02:07:44 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# define CMD_PA 0
# define CMD_PB 1
# define CMD_SA 2
# define CMD_SB 3
# define CMD_SS 4
# define CMD_RA 5
# define CMD_RB 6
# define CMD_RR 7
# define CMD_RRA 8
# define CMD_RRB 9
# define CMD_RRR 10

typedef struct s_opt_queue
{
	struct s_opt_list	*head;
	struct s_opt_list	*tail;
}t_opt_queue;

typedef struct s_opt_list
{
	int					cmd_num;
	struct s_opt_list	*next;
	struct s_opt_list	*prev;
}t_opt_list;

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

void				radix_sort_base3(t_stacks *stacks, t_opt_queue *opt_queue);

void				merge_b_to_a(t_stacks *stacks,
						t_opt_queue *opt_queue,
						int a_merge_size,
						int b_merge_size);
void				sort_2_elem(t_stacks *stacks, t_opt_queue *opt_queue);
void				sort_3_elem(t_stacks *stacks, t_opt_queue *opt_queue);
void				sort_4_elem(t_stacks *stacks, t_opt_queue *opt_queue);
void				sort_5_elem(t_stacks *stacks, t_opt_queue *opt_queue);

t_opt_list			*opt_init_node(int cmd_num);
void				opt_add_node(t_opt_queue *opt_queue, int cmd_num);
void				opt_del_tail(t_opt_queue *opt_queue);		
void				execute_command_with_opt(t_stacks *stacks,
						t_opt_queue *opt_queue,
						int cmd_num,
						void (*f)(t_stacks *));	
t_opt_queue			*init_opt_queue(void);
void				print_cmd_list(t_opt_queue *opt_queue);

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