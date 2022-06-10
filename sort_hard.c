/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:19:40 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 17:47:43 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_elem(t_stacks *stacks, t_opt_queue *opt_queue)
{
	int	elem1;
	int	elem2;

	elem1 = stacks->a->top->index;
	elem2 = stacks->a->top->prev->index;
	if (elem1 > elem2)
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
	if (elem1 == 0 && elem2 == 2 && elem3 == 1)
	{
		execute_command_with_opt(stacks, opt_queue, CMD_SA, &sa);
		execute_command_with_opt(stacks, opt_queue, CMD_RA, &ra);
	}
	else if (elem1 == 1 && elem2 == 0 && elem3 == 2)
		execute_command_with_opt(stacks, opt_queue, CMD_SA, &sa);
	else if (elem1 == 1 && elem2 == 2 && elem3 == 0)
		execute_command_with_opt(stacks, opt_queue, CMD_RRA, &rra);
	else if (elem1 == 2 && elem2 == 0 && elem3 == 1)
		execute_command_with_opt(stacks, opt_queue, CMD_RA, &ra);
	else if (elem1 == 2 && elem2 == 1 && elem3 == 0)
	{
		execute_command_with_opt(stacks, opt_queue, CMD_SA, &sa);
		execute_command_with_opt(stacks, opt_queue, CMD_RRA, &rra);
	}
}
