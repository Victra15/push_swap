/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:06:44 by yolee             #+#    #+#             */
/*   Updated: 2022/06/16 02:08:18 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_merge_cmd(t_stacks *stacks,
						t_opt_queue *opt_queue,
						int merge_cmd,
						int *merge_size)
{
	if (merge_cmd == 1)
	{
		execute_command_with_opt(stacks, opt_queue, CMD_RRA, &rra);
		execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
	}
	else if (merge_cmd == 2)
		execute_command_with_opt(stacks, opt_queue, CMD_RRB, &rrb);
	else if (merge_cmd == 3)
	{
		execute_command_with_opt(stacks, opt_queue, CMD_RRB, &rrb);
		execute_command_with_opt(stacks, opt_queue, CMD_PA, &pa);
	}
	else if (merge_cmd == 4)
		execute_command_with_opt(stacks, opt_queue, CMD_RRA, &rra);
	(*merge_size)--;
}

void	merge_b_to_a(t_stacks *stacks,
					t_opt_queue *opt_queue,
					int a_merge_size,
					int b_merge_size)
{
	while (a_merge_size > 0 && b_merge_size > 0)
	{
		if (stacks->b->bottom->index > stacks->a->bottom->index)
			execute_merge_cmd(stacks, opt_queue, 3, &b_merge_size);
		else
			execute_merge_cmd(stacks, opt_queue, 4, &a_merge_size);
	}
	while (b_merge_size > 0)
		execute_merge_cmd(stacks, opt_queue, 3, &b_merge_size);
	while (a_merge_size > 0)
		execute_merge_cmd(stacks, opt_queue, 4, &a_merge_size);
}
