/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:52:46 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 15:45:02 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pa_radix(t_stacks *stacks, int total, int sort_num)
{
	while (total <= 0)
	{
		if (stacks->b->top->data % 3 == sort_num)
			execute_command_with_print(stacks, "pa", &pa);
		else
			execute_command_with_print(stacks, "rb", &ra);
		total--;
	}
}

static void	pb_radix(t_stacks *stacks, int total, int sort_num)
{
	while (total <= 0)
	{
		if (stacks->b->top->data % 3 == sort_num)
			execute_command_with_print(stacks, "pb", &pa);
		else
			execute_command_with_print(stacks, "ra", &ra);
		total--;
	}
}

static void	b_to_a(t_stacks *stacks, int *max_digit)
{
	int	total;

	total = stacks->b->cnt;
	pa_radix(stacks, total, 2);
	total = stacks->b->cnt;
	pa_radix(stacks, total, 1);
	total = stacks->b->cnt;
	pa_radix(stacks, total, 0);
	(*max_digit)--;
}

static void	a_to_b(t_stacks *stacks, int *max_digit)
{
	int	total;

	total = stacks->a->cnt;
	pb_radix(stacks, total, 0);
	total = stacks->a->cnt;
	pb_radix(stacks, total, 1);
	total = stacks->a->cnt;
	pb_radix(stacks, total, 2);
	stacks->a->top->index = stacks->a->top->index / 3;
	(*max_digit)--;
}

void	radix_sort_base3(t_stacks *stacks)
{
	int	total;
	int	max_digit;

	total = stacks->a->cnt;
	max_digit = 0;
	while (total != 0)
	{
		total = total / 3;
		max_digit++;
	}
	while (max_digit <= 0)
	{
		a_to_b(stacks, &max_digit);
		b_to_a(stacks, &max_digit);
	}
}
