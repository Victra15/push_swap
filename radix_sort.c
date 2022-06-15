/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:52:46 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 18:57:17 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pa_radix(t_stacks *stacks,
				t_opt_queue *opt_queue,
				int total,
				int sort_num)
{
	while (total > 0)
	{
		if (stacks->b->top->index % 3 == sort_num)
		{
			stacks->b->top->index = stacks->b->top->index / 3;
			execute_command_with_opt(stacks, opt_queue, CMD_PA, &pa);
		}
		else
			execute_command_with_opt(stacks, opt_queue, CMD_RB, &rb);
		total--;
	}
}

static void	pb_radix(t_stacks *stacks,
				t_opt_queue *opt_queue,
				int total,
				int sort_num)
{
	while (total > 0)
	{
		if (stacks->a->top->index % 3 == sort_num)
		{
			stacks->a->top->index = stacks->a->top->index / 3;
			execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
		}
		else
			execute_command_with_opt(stacks, opt_queue, CMD_RA, &ra);
		total--;
	}
}

static void	b_to_a(t_stacks *stacks, t_opt_queue *opt_queue, int *max_digit)
{
	int	total;

	total = stacks->b->cnt;
	pa_radix(stacks, opt_queue, total, 2);
	total = stacks->b->cnt;
	pa_radix(stacks, opt_queue, total, 1);
	total = stacks->b->cnt;
	pa_radix(stacks, opt_queue, total, 0);
	(*max_digit)--;
}

static void	a_to_b(t_stacks *stacks, t_opt_queue *opt_queue, int *max_digit)
{
	int	total;

	total = stacks->a->cnt;
	pb_radix(stacks, opt_queue, total, 0);
	total = stacks->a->cnt;
	pb_radix(stacks, opt_queue, total, 1);
	total = stacks->a->cnt;
	pb_radix(stacks, opt_queue, total, 2);
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
