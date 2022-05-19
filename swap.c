/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:54:18 by yolee             #+#    #+#             */
/*   Updated: 2022/05/16 18:25:17 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack	*stack)
{
	t_list	*temp1;
	t_list	*temp2;

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
