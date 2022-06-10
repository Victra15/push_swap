/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:52:46 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 18:45:07 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	pa_radix(t_stacks *stacks,
// 				t_opt_queue *opt_queue,
// 				int total,
// 				int sort_num)
// {
// 	while (total > 0)
// 	{
// 		if (stacks->b->top->index % 3 == sort_num)
// 		{
// 			stacks->b->top->index = stacks->b->top->index / 3;
// 			execute_command_with_opt(stacks, opt_queue, CMD_PA, &pa);
// 		}
// 		else
// 			execute_command_with_opt(stacks, opt_queue, CMD_RB, &rb);
// 		total--;
// 	}
// }

// static void	pb_radix(t_stacks *stacks,
// 				t_opt_queue *opt_queue,
// 				int total,
// 				int sort_num)
// {
// 	while (total > 0)
// 	{
// 		if (stacks->a->top->index % 3 == sort_num)
// 		{
// 			stacks->a->top->index = stacks->a->top->index / 3;
// 			execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
// 		}
// 		else
// 			execute_command_with_opt(stacks, opt_queue, CMD_RA, &ra);
// 		total--;
// 	}
// }

static void	b_to_a(t_stacks *stacks, t_opt_queue *opt_queue, int *max_digit)
{
	int	total;
	int	mod_0_cnt;

	total = stacks->a->cnt;
	mod_0_cnt = 0;
	if (stacks->b->top->index % 3 == 2)
	{
		stacks->b->top->index = stacks->a->top->index / 3;
		execute_command_with_opt(stacks, opt_queue, CMD_PA, &pa);
	}
	else if (stacks->b->top->index % 3 == 1)
	{
		stacks->b->top->index = stacks->a->top->index / 3;
		execute_command_with_opt(stacks, opt_queue, CMD_RB, &rb);
	}
	else
	{
		stacks->b->top->index = stacks->a->top->index / 3;
		execute_command_with_opt(stacks, opt_queue, CMD_PA, &pa);
		execute_command_with_opt(stacks, opt_queue, CMD_RA, &ra);
		mod_0_cnt++;
	}
	while (stacks->b->top != NULL)
		execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
	while (mod_0_cnt > 0)
	{
		execute_command_with_opt(stacks, opt_queue, CMD_RRA, &rra);
		mod_0_cnt--;
	}
	(*max_digit)--;
}

static void	a_to_b(t_stacks *stacks, t_opt_queue *opt_queue, int *max_digit)
{
	int	total;
	int	mod_2_cnt;

	total = stacks->a->cnt;
	mod_2_cnt = 0;
	if (stacks->a->top->index % 3 == 0)
	{
		stacks->a->top->index = stacks->a->top->index / 3;
		execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
	}
	else if (stacks->a->top->index % 3 == 1)
	{
		stacks->a->top->index = stacks->a->top->index / 3;
		execute_command_with_opt(stacks, opt_queue, CMD_RA, &ra);
	}
	else
	{
		stacks->a->top->index = stacks->a->top->index / 3;
		execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
		execute_command_with_opt(stacks, opt_queue, CMD_RB, &rb);
		mod_2_cnt++;
	}
	while (stacks->a->top != NULL)
		execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
	while (mod_2_cnt > 0)
	{
		execute_command_with_opt(stacks, opt_queue, CMD_RRB, &rrb);
		mod_2_cnt--;
	}
	(*max_digit)--;
}

void	radix_sort_base3(t_stacks *stacks, t_opt_queue *opt_queue)
{
	int	total;
	int	max_digit;

	total = stacks->a->cnt;
	max_digit = 0;
	while (total != 0)
	{
		total = total / 3;
		max_digit++;
	}
	while (max_digit > 0)
	{
		a_to_b(stacks, opt_queue, &max_digit);
		if (max_digit > 0)
			b_to_a(stacks, opt_queue, &max_digit);
		else
			while (stacks->b->cnt > 0)
				execute_command_with_opt(stacks, opt_queue, CMD_PA, &pa);
	}
}
