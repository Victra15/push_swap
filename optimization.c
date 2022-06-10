/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:00:25 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 17:53:42 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opt_list	*opt_init_node(int cmd_num)
{
	t_opt_list	*new_node;

	new_node = (t_opt_list *)malloc(sizeof(t_opt_list));
	if (new_node == NULL)
		exit(1);
	new_node->cmd_num = cmd_num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
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

void	opt_add_node(t_opt_queue *opt_queue, int cmd_num)
{
	t_opt_list	*new_node;

	if (opt_queue->tail != NULL
		&& new_is_reverse_operator(opt_queue->tail->cmd_num, cmd_num))
	{
		opt_del_tail(opt_queue);
		return ;
	}
	new_node = opt_init_node(cmd_num);
	if (opt_queue->tail == NULL)
		opt_queue->head = new_node;
	else
	{
		opt_queue->tail->next = new_node;
		new_node->prev = opt_queue->tail;
	}
	opt_queue->tail = new_node;
}

void	opt_del_tail(t_opt_queue *opt_queue)
{
	t_opt_list	*temp;

	if (opt_queue->tail->prev == NULL)
	{
		free(opt_queue->head);
		free(opt_queue->tail);
	}
	else
	{
		temp = opt_queue->tail;
		opt_queue->tail = opt_queue->tail->prev;
		free(temp);
		opt_queue->tail->next = NULL;
	}
}

void	execute_command_with_opt(t_stacks *stacks,
						t_opt_queue *opt_queue,
						int cmd_num,
						void (*f)(t_stacks *))
{
	opt_add_node(opt_queue, cmd_num);
	f(stacks);
}
