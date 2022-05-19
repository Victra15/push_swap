/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:04:50 by yolee             #+#    #+#             */
/*   Updated: 2022/05/16 16:29:47 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_list	*temp;

	temp = pop(stacks->b);
	push(stacks->a, temp);
}

void	pb(t_stacks *stacks)
{
	t_list	*temp;

	temp = pop(stacks->a);
	push(stacks->b, temp);
}
