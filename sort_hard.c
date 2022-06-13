/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:19:40 by yolee             #+#    #+#             */
/*   Updated: 2022/06/14 04:59:33 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_elem(t_stacks *stacks, t_opt_queue *opt_queue)
{
	if (stacks->a->top->index > stacks->a->top->prev->index)
		execute_command_with_opt(stacks, opt_queue, CMD_SA, &sa);
}

void	sort_3_elem(t_stacks *stacks, t_opt_queue *opt_queue)
{
	int	elem1;
	int	elem2;
	int	elem3;

	elem1 = stacks->a->top->index;
	elem2 = stacks->a->top->prev->index;
	elem3 = stacks->a->top->prev->prev->index;
	if (elem3 > elem1 && elem1 > elem2)
		execute_command_with_opt(stacks, opt_queue, CMD_SA, &sa);
	else if (elem2 > elem3 && elem3 > elem1)
	{
		execute_command_with_opt(stacks, opt_queue, CMD_SA, &sa);
		execute_command_with_opt(stacks, opt_queue, CMD_RA, &ra);
	}
	else if (elem2 > elem1 && elem1 > elem3)
		execute_command_with_opt(stacks, opt_queue, CMD_RRA, &rra);
	else if (elem1 > elem3 && elem3 > elem2)
		execute_command_with_opt(stacks, opt_queue, CMD_RA, &ra);
	else if (elem1 > elem2 && elem2 > elem3)
	{
		execute_command_with_opt(stacks, opt_queue, CMD_SA, &sa);
		execute_command_with_opt(stacks, opt_queue, CMD_RRA, &rra);
	}
}

void	sort_4_elem(t_stacks *stacks, t_opt_queue *opt_queue)
{
	execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
	execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
	if (stacks->b->top->index > stacks->b->top->prev->index)
		execute_command_with_opt(stacks, opt_queue, CMD_SB, &sb);
	sort_2_elem(stacks, opt_queue);
	merge_b_to_a(stacks, opt_queue, 2, 2);
}

void	sort_5_elem(t_stacks *stacks, t_opt_queue *opt_queue)
{
	execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
	execute_command_with_opt(stacks, opt_queue, CMD_PB, &pb);
	if (stacks->b->top->index > stacks->b->top->prev->index)
		execute_command_with_opt(stacks, opt_queue, CMD_SB, &sb);
	sort_3_elem(stacks, opt_queue);
	merge_b_to_a(stacks, opt_queue, 3, 2);
}
