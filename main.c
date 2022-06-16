/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:51:31 by yolee             #+#    #+#             */
/*   Updated: 2022/06/17 04:06:55 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_already_sorted(t_stacks *stacks)
{
	t_double_llst	*iter;

	iter = stacks->a->top;
	while (iter->prev != NULL)
	{
		if (iter->index > iter->prev->index)
			return (0);
		iter = iter->prev;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_opt_queue	*opt_queue;

	stacks = init_stacks(argc, argv);
	if (is_already_sorted(stacks))
		return (0);
	opt_queue = init_opt_queue();
	if (stacks->a->cnt == 2)
		sort_2_elem(stacks, opt_queue);
	else if (stacks->a->cnt == 3)
		sort_3_elem(stacks, opt_queue);
	else if (stacks->a->cnt == 4)
		sort_4_elem(stacks, opt_queue);
	else if (stacks->a->cnt == 5)
		sort_5_elem(stacks, opt_queue);
	else if (stacks->a->cnt > 5)
		radix_sort_base3(stacks, opt_queue);
	print_cmd_list(opt_queue);
	return (0);
}
