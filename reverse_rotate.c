/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:09:29 by yolee             #+#    #+#             */
/*   Updated: 2022/05/16 18:25:47 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_list	*temp;

	temp = pop_bottom(stack);
	push(stack, temp);
}

void	rra(t_stacks *stacks)
{
	reverse_rotate(stacks->a);
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(stacks->b);
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
}
