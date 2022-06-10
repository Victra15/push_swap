/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:59:27 by yolee             #+#    #+#             */
/*   Updated: 2022/06/04 23:32:04 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double_llst	*pop(t_stack *stack)
{
	t_double_llst	*temp;

	if (stack == NULL || stack->cnt == 0)
		return (NULL);
	else
	{
		temp = stack->top;
		stack->top = stack->top->prev;
		if (stack->cnt == 1)
			stack->bottom = stack->top;
		if (stack->top != NULL)
			stack->top->next = NULL;
		temp->prev = NULL;
	}
	stack->cnt--;
	return (temp);
}

t_double_llst	*pop_bottom(t_stack *stack)
{
	t_double_llst	*temp;

	if (stack == NULL || stack->cnt == 0)
		return (NULL);
	else
	{
		temp = stack->bottom;
		stack->bottom = stack->bottom->next;
		if (stack->cnt == 1)
			stack->top = stack->bottom;
		if (stack->bottom != NULL)
			stack->bottom->prev = NULL;
		temp->next = NULL;
	}
	stack->cnt--;
	return (temp);
}

void	push(t_stack *stack, t_double_llst *node)
{
	if (node == NULL || stack == NULL)
		return ;
	if (stack->cnt == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->top->next = node;
		node->prev = stack->top;
		stack->top = node;
	}
	stack->cnt++;
}

void	push_bottom(t_stack *stack, t_double_llst *node)
{
	if (node == NULL || stack == NULL)
		return ;
	if (stack->cnt == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->prev = node;
		node->next = stack->bottom;
		stack->bottom = node;
	}
	stack->cnt++;
}
