/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:00:25 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 14:52:07 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opt_list	*opt_init_node(int command_num)
{
	t_opt_list	*new_node;

	new_node = (t_opt_list *)malloc(sizeof(t_opt_list));
	if (new_node == NULL)
		exit(1);
	new_node->command_num = command_num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	opt_add_node(t_opt_queue *opt_queue, int command_num)
{
	t_opt_list	*new_node;

	new_node = opt_init_node(command_num);
	if (opt_queue->tail == NULL)
		opt_queue->head = new_node;
	else
	{
		opt_queue->tail->next = new_node;
		new_node->prev = opt_queue->tail;
	}
	opt_queue->tail = new_node;
}

void	opt_replace(t_opt_list *del_head,
				t_opt_list *del_tail,
				t_opt_list *new_head,
				t_opt_list *new_tail)
{
	new_head->prev = del_head->prev;
	new_tail->next = del_tail->next;
	del_head->prev = NULL;
	del_tail->next = NULL;
	free_list(del_head);
}

void	free_list(t_opt_list *iter)
{
	while (iter != NULL)
	{
		free(iter);
		iter = iter->next;
	}
}

void	optimization(t_opt_list **opt_loc)
{
	if ((*opt_loc)->command_num == COMMAND_PA)
		opt_pa(*opt_loc);
	else if ((*opt_loc)->command_num == COMMAND_PB)
		opt_pb(*opt_loc);
	else if ((*opt_loc)->command_num == COMMAND_SA)
		opt_sa(*opt_loc);
	else if ((*opt_loc)->command_num == COMMAND_SB)
		opt_sb(*opt_loc);
	else if ((*opt_loc)->command_num == COMMAND_SS)
		opt_ss(*opt_loc);
	else if ((*opt_loc)->command_num == COMMAND_RA)
		opt_ra(*opt_loc);
	else if ((*opt_loc)->command_num == COMMAND_RB)
		opt_rb(*opt_loc);
	else if ((*opt_loc)->command_num == COMMAND_RR)
		opt_rr(*opt_loc);
	else if ((*opt_loc)->command_num == COMMAND_RRA)
		opt_rra(*opt_loc);
	else if ((*opt_loc)->command_num == COMMAND_RRB)
		opt_rrb(*opt_loc);
	else if ((*opt_loc)->command_num == COMMAND_RRR)
		opt_rrr(*opt_loc);
}
