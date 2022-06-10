/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:51:31 by yolee             #+#    #+#             */
/*   Updated: 2022/06/09 16:55:50 by yolee            ###   ########.fr       */
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

void	radix_sort(t_stacks *stacks)
{
	int	sort_bit;
	int	total;
	int	loop;
	int	cnt;

	total = stacks->a->cnt;
	cnt = 0;
	sort_bit = 1;
	while (sort_bit < total)
	{
		loop = 0;
		while (loop < total)
		{
			if (sort_bit & stacks->a->top->index)
			{
				ft_printf("ra");
				ra(stacks);
			}
			else
			{
				ft_printf("pb");
				pb(stacks);
			}
			loop++;
			cnt++;
		}
		while (stacks->b->top != NULL)
		{
			ft_printf("pa");
			pa(stacks);
			cnt++;
		}
		ft_printf("\n");
		print_stacks(stacks);
		sort_bit = sort_bit << 1;
	}
	ft_printf("%d\n", cnt);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = init_stacks(argc, argv);
	radix_sort(stacks);
	return (0);
}
