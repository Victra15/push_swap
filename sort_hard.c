/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:19:40 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 15:46:45 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_elem(t_stacks *stacks)
{
	int	elem1;
	int	elem2;

	elem1 = stacks->a->top->data;
	elem2 = stacks->a->top->prev->data;
	if (elem1 > elem2)
		execute_command_with_print(stacks, "sa", &sa);
}

void	sort_3_elem(t_stacks *stacks)
{
	int	elem1;
	int	elem2;
	int	elem3;

	elem1 = stacks->a->top->data;
	elem2 = stacks->a->top->prev->data;
	elem3 = stacks->a->top->prev->prev->data;
	if (elem1 == 0 && elem2 == 2 && elem3 == 1)
	{
		execute_command_with_print(stacks, "sa", &sa);
		execute_command_with_print(stacks, "ra", &ra);
	}
	else if (elem1 == 1 && elem2 == 0 && elem3 == 2)
		execute_command_with_print(stacks, "sa", &sa);
	else if (elem1 == 1 && elem2 == 2 && elem3 == 0)
		execute_command_with_print(stacks, "rra", &rra);
	else if (elem1 == 2 && elem2 == 0 && elem3 == 1)
		execute_command_with_print(stacks, "ra", &ra);
	else if (elem1 == 2 && elem2 == 1 && elem3 == 0)
	{
		execute_command_with_print(stacks, "sa", &sa);
		execute_command_with_print(stacks, "rra", &rra);
	}
}
