/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_merge_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:42:36 by yolee             #+#    #+#             */
/*   Updated: 2022/06/14 04:03:24 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_merge_sort(t_stacks *stacks, t_opt_queue *opt_queue)
{
	t_double_llst	*iter;

	
	iter = stacks->a->top;
	while (iter != NULL)
	{
		iter->index;
		iter = iter->prev;
	}
}
