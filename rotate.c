/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:55:21 by yolee             #+#    #+#             */
/*   Updated: 2022/05/16 18:25:37 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_list	*temp;

	temp = pop(stack);
	push_bottom(stack, temp);
}

void	ra(t_stacks *stacks)
{
	rotate(stacks->a);
}

void	rb(t_stacks *stacks)
{
	rotate(stacks->b);
}

void	rr(t_stacks *stacks)
{
	rotate(stacks->a);
	rotate(stacks->b);
}
