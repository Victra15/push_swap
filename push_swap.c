/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:51:31 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 17:52:42 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	t_double_llst	*iter_a;
	t_double_llst	*iter_b;

	iter_a = stacks->a->top;
	iter_b = stacks->b->top;
	ft_printf("a\t\tb");
	ft_printf("\n");
	ft_printf("-\t\t-");
	ft_printf("\n");
	while (iter_a != NULL || iter_b != NULL)
	{
		if (iter_a != NULL)
		{
			ft_printf("%d", iter_a->data);
			ft_printf("\t");
			iter_a = iter_a->prev;
		}
		else
			ft_printf("\t");
		ft_printf("\t");
		if (iter_b != NULL)
		{
			ft_printf("%d", iter_b->data);
			iter_b = iter_b->prev;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

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
	else if (stacks->a->cnt > 3)
		radix_sort_base3(stacks, opt_queue);
	print_cmd_list(opt_queue);
	return (0);
}
