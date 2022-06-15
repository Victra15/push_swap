/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:52:26 by yolee             #+#    #+#             */
/*   Updated: 2022/06/16 02:00:48 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	new_is_combinable(int opt_tail_cmd_num,
				int cmd_num,
				int *combined_cmd)
{
	if ((opt_tail_cmd_num == CMD_RRA && cmd_num == CMD_RRB)
		|| (opt_tail_cmd_num == CMD_RRB && cmd_num == CMD_RRA))
	{
		(*combined_cmd) = CMD_RRR;
		return (1);
	}
	if ((opt_tail_cmd_num == CMD_RA && cmd_num == CMD_RB)
		|| (opt_tail_cmd_num == CMD_RB && cmd_num == CMD_RA))
	{
		(*combined_cmd) = CMD_RR;
		return (1);
	}
	if ((opt_tail_cmd_num == CMD_SA && cmd_num == CMD_SB)
		|| (opt_tail_cmd_num == CMD_SB && cmd_num == CMD_SA))
	{
		(*combined_cmd) = CMD_SS;
		return (1);
	}
	return (0);
}

static int	new_is_reverse_operator(int opt_tail_cmd_num, int cmd_num)
{
	if (opt_tail_cmd_num == CMD_PA && cmd_num == CMD_PB)
		return (1);
	if (opt_tail_cmd_num == CMD_PB && cmd_num == CMD_PA)
		return (1);
	if (opt_tail_cmd_num == CMD_SA && cmd_num == CMD_SA)
		return (1);
	if (opt_tail_cmd_num == CMD_SB && cmd_num == CMD_SB)
		return (1);
	if (opt_tail_cmd_num == CMD_SS && cmd_num == CMD_SS)
		return (1);
	if (opt_tail_cmd_num == CMD_RA && cmd_num == CMD_RRA)
		return (1);
	if (opt_tail_cmd_num == CMD_RB && cmd_num == CMD_RRB)
		return (1);
	if (opt_tail_cmd_num == CMD_RR && cmd_num == CMD_RRR)
		return (1);
	if (opt_tail_cmd_num == CMD_RRA && cmd_num == CMD_RA)
		return (1);
	if (opt_tail_cmd_num == CMD_RRB && cmd_num == CMD_RB)
		return (1);
	if (opt_tail_cmd_num == CMD_RRR && cmd_num == CMD_RR)
		return (1);
	return (0);
}

void	execute_command_with_opt(t_stacks *stacks,
						t_opt_queue *opt_queue,
						int cmd_num,
						void (*f)(t_stacks *))
{
	int	combined_cmd;

	if (opt_queue->tail != NULL
		&& new_is_reverse_operator(opt_queue->tail->cmd_num, cmd_num))
		opt_del_tail(opt_queue);
	else if (opt_queue->tail != NULL
		&& new_is_combinable(opt_queue->tail->cmd_num, cmd_num, &combined_cmd))
	{
		opt_del_tail(opt_queue);
		opt_add_node(opt_queue, combined_cmd);
	}
	else
		opt_add_node(opt_queue, cmd_num);
	f(stacks);
}
