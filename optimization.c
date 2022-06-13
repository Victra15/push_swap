/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:00:25 by yolee             #+#    #+#             */
/*   Updated: 2022/06/14 03:31:01 by yolee            ###   ########.fr       */
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

void	opt_add_node(t_opt_queue *opt_queue, int cmd_num)
{
	t_opt_list	*new_node;

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
