/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:05:12 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 17:40:30 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_opt_queue	*init_opt_queue(void)
{
	t_opt_queue	*new_opt_queue;

	new_opt_queue = (t_opt_queue *)malloc(sizeof(t_opt_queue));
	if (new_opt_queue == NULL)
		exit(1);
	new_opt_queue->head = NULL;
	new_opt_queue->tail = NULL;
	return (new_opt_queue);
}

static void	print_cmd(int cmd_num)
{
	if (cmd_num == CMD_PA)
		ft_printf("pa\n");
	else if (cmd_num == CMD_PB)
		ft_printf("pb\n");
	else if (cmd_num == CMD_SA)
		ft_printf("sa\n");
	else if (cmd_num == CMD_SB)
		ft_printf("sb\n");
	else if (cmd_num == CMD_SS)
		ft_printf("ss\n");
	else if (cmd_num == CMD_RA)
		ft_printf("ra\n");
	else if (cmd_num == CMD_RB)
		ft_printf("rb\n");
	else if (cmd_num == CMD_RR)
		ft_printf("rr\n");
	else if (cmd_num == CMD_RRA)
		ft_printf("rra\n");
	else if (cmd_num == CMD_RRB)
		ft_printf("rrb\n");
	else if (cmd_num == CMD_RRR)
		ft_printf("rrr\n");
}

void	print_cmd_list(t_opt_queue *opt_queue)
{
	t_opt_list	*iter;

	iter = opt_queue->head;
	while (iter != NULL)
	{
		print_cmd(iter->cmd_num);
		iter = iter->next;
	}
}
