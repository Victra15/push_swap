/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:39:31 by yolee             #+#    #+#             */
/*   Updated: 2022/06/14 04:17:30 by yolee            ###   ########.fr       */
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

void	merge_a_to_b(t_stacks *stacks,
					t_opt_queue *opt_queue,
					int a_merge_size,
					int b_merge_size)
{
	while (a_merge_size > 0 && b_merge_size > 0)
	{
		if (stacks->a->bottom->index > stacks->b->bottom->index)
			execute_merge_cmd(stacks, opt_queue, 1, &a_merge_size);
		else
			execute_merge_cmd(stacks, opt_queue, 2, &b_merge_size);
	}
	while (a_merge_size > 0)
		execute_merge_cmd(stacks, opt_queue, 1, &a_merge_size);
	while (b_merge_size > 0)
		execute_merge_cmd(stacks, opt_queue, 2, &b_merge_size);
}

static void	merge(t_stacks *stacks, t_opt_queue *opt_queue, int total)
{
	int	merge_size;
	int	a_size;
	int	b_size;
	int	a_merge_size;
	int	b_merge_size;

	merge_size = 1;
	while (merge_size < total)
	{
		a_size = stacks->a->cnt;
		b_size = stacks->b->cnt;
		while (a_size > 0 || b_size > 0)
		{
			calc_merge_size(&a_size, &a_merge_size, merge_size);
			calc_merge_size(&b_size, &b_merge_size, merge_size);
			merge_b_to_a(stacks, opt_queue, a_merge_size, b_merge_size);
			if (a_size > 0 || b_size > 0)
			{
				calc_merge_size(&a_size, &a_merge_size, merge_size);
				calc_merge_size(&b_size, &b_merge_size, merge_size);
				merge_a_to_b(stacks, opt_queue, a_merge_size, b_merge_size);
			}
		}
		merge_size = merge_size << 1;
	}
}

void	merge_sort(t_stacks *stacks, t_opt_queue *opt_queue)
{
	int	total;
	int	loop;

	total = stacks->a->cnt;
	loop = 0;
	while (loop < total / 2)
	{
		execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
		loop++;
	}
	merge(stacks, opt_queue, total);
}
