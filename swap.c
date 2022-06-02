/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:54:18 by yolee             #+#    #+#             */
/*   Updated: 2022/06/01 20:45:21 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack	*stack)
{
	t_double_llst	*temp1;
	t_double_llst	*temp2;

	if (stack->cnt < 2)
		return ;
	else
	{
		temp1 = pop(stack);
		temp2 = pop(stack);
		push(stack, temp2);
		push(stack, temp1);
	}
}

void	sa(t_stacks *stacks)
{
	swap(stacks->a);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->b);
}

void	ss(t_stacks *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
}
