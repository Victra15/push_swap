/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:55:33 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 14:55:47 by yolee            ###   ########.fr       */
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
			ft_printf("%d", iter_a->index);
			ft_printf("\t");
			iter_a = iter_a->prev;
		}
		else
			ft_printf("\t");
		ft_printf("\t");
		if (iter_b != NULL)
		{
			ft_printf("%d", iter_b->index);
			iter_b = iter_b->prev;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}
