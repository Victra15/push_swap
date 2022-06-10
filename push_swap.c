/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:51:31 by yolee             #+#    #+#             */
/*   Updated: 2022/06/10 15:41:59 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_command_with_print(t_stacks *stacks,
							char *command_name,
							void (*f)(t_stacks *))
{
	ft_printf("%s\n", command_name);
	f(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = init_stacks(argc, argv);
	if (stacks->a->cnt == 2)
		sort_2_elem(stacks);
	else if (stacks->a->cnt == 3)
		sort_2_elem(stacks);
	else if (stacks->a->cnt > 3)
		radix_sort_base3(stacks);
	return (0);
}
