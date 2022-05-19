/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:51:29 by yolee             #+#    #+#             */
/*   Updated: 2022/05/16 18:25:02 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

typedef struct s_stack
{	
	size_t			cnt;
	struct s_list	*top;
	struct s_list	*bottom;
}t_stack;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
}t_stacks;

t_list		*init_lst(void);
t_stack		*init_stack(void);
t_stacks	*init_stacks(void);

t_list		*pop(t_stack *stack);
t_list		*pop_bottom(t_stack *stack);
void		*push(t_stack *stack, t_list *new);
void		*push_bottom(t_stack *stack, t_list *new);

void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);

void		swap(t_stack *stack);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);

void		rotate(t_stack *stack);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);

void		reverse_rotate(t_stack *stack);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
#endif