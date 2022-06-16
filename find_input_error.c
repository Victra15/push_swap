/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_input_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:27:07 by yolee             #+#    #+#             */
/*   Updated: 2022/06/17 03:20:01 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "error\n", 6);
	exit(EXIT_FAILURE);
}

static int	ft_issign(char ch)
{
	if (ch == '+' || ch == '-')
		return (1);
	else
		return (0);
}

void	find_input_error(char *input)
{
	int	digit_find_flag;

	digit_find_flag = 0;
	if ((*input) == '\0')
		print_error();
	while ((*input) != '\0')
	{
		if (ft_issign(*input))
		{	
			input++;
			if (!ft_isdigit(*input))
				print_error();
		}
		if (ft_isdigit(*input))
			digit_find_flag = 1;
		if (!ft_isdigit(*input) && *input != ' ')
			print_error();
		input++;
	}
	if (digit_find_flag == 0)
		print_error();
}
