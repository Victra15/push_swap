/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:51:31 by yolee             #+#    #+#             */
/*   Updated: 2022/06/02 16:11:04 by yolee            ###   ########.fr       */
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
}

void	print_pattern(t_stacks stacks, void (*f)(t_stacks *), int level)
{
	// pa pb sa sb ss sb ra rb rr rra rrb rrr
	f(&stacks);
	print_stacks(&stacks);
	if (level < 2)
	{
		ft_printf("pa\n");
		print_pattern(stacks, &pa, level + 1);
		ft_printf("pb\n");
		print_pattern(stacks, &pb, level + 1);
		// print_pattern(stacks, &sa, level + 1);
		// print_pattern(stacks, &sb, level + 1);
		// print_pattern(stacks, &ss, level + 1);
		// print_pattern(stacks, &ra, level + 1);
		// print_pattern(stacks, &rb, level + 1);
		// print_pattern(stacks, &rr, level + 1);
		// print_pattern(stacks, &rra, level + 1);
		// print_pattern(stacks, &rrb, level + 1);
		// print_pattern(stacks, &rrr, level + 1);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = init_stacks(stacks, argc, argv);
	pb(stacks);
	pb(stacks);
	pb(stacks);
	print_pattern(*stacks, &pa, 1);
	// print_pattern(*stacks, &pb, 1);
	// print_pattern(*stacks, &sa, 1);
	// print_pattern(*stacks, &sb, 1);
	// print_pattern(*stacks, &ss, 1);
	// print_pattern(*stacks, &ra, 1);
	// print_pattern(*stacks, &rb, 1);
	// print_pattern(*stacks, &rr, 1);
	// print_pattern(*stacks, &rra, 1);
	// print_pattern(*stacks, &rrb, 1);
	// print_pattern(*stacks, &rrr, 1);
	return (0);
}
