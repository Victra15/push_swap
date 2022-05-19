/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:59:27 by yolee             #+#    #+#             */
/*   Updated: 2022/05/16 18:05:53 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*pop(t_stack *stack)
{
	t_list	*temp;

	if (stack == NULL || stack->cnt == 0)
		return (NULL);
	else
	{
		temp = stack->top;
		stack->top = stack->top->prev;
		if (stack->cnt == 1)
			stack->bottom = stack->top;
		temp->prev == NULL;
	}
	stack->cnt--;
	return (temp);
}

t_list	*pop_bottom(t_stack *stack)
{
	t_list	*temp;

	if (stack == NULL || stack->cnt == 0)
		return (NULL);
	else
	{
		temp = stack->bottom;
		stack->bottom = stack->bottom->next;
		if (stack->cnt == 1)
			stack->top = stack->bottom;
		temp->next == NULL;
	}
	stack->cnt--;
	return (temp);
}

void	*push(t_stack *stack, t_list *new)
{
	if (new == NULL || stack == NULL)
		return ;
	if (stack->cnt == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->top->next = new;
		new->prev = stack->top;
		stack->top = new;
	}
	stack->cnt++;
}

void	*push_bottom(t_stack *stack, t_list *new)
{
	if (new == NULL || stack == NULL)
		return ;
	if (stack->cnt == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->bottom->prev = new;
		new->next = stack->bottom;
		stack->bottom = new;
	}
	stack->cnt++;
}
