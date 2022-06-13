/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:51:31 by yolee             #+#    #+#             */
/*   Updated: 2022/06/14 04:58:48 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_opt_queue	*opt_queue;

	stacks = init_stacks(argc, argv);
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
		merge_sort(stacks, opt_queue);
	print_cmd_list(opt_queue);
	return (0);
}
