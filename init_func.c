/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:13:04 by yolee             #+#    #+#             */
/*   Updated: 2022/05/16 18:26:06 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_lst(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*init_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->cnt = 0;
	new->top = NULL;
	new->bottom = NULL;
	return (new);
}

t_stacks	*init_stacks(void)
{
	t_stacks	*new;

	new = (t_stacks *)malloc(sizeof(t_stacks));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->a = init_stack();
	new->b = init_stack();
	return (new);
}
