/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_size_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:59:08 by yolee             #+#    #+#             */
/*   Updated: 2022/06/16 01:59:17 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_merge_size(int *total_size,
					int *adj_merge_size,
					int merge_size)
{
	if ((*total_size) >= merge_size)
	{
		(*adj_merge_size) = merge_size;
		(*total_size) = (*total_size) - merge_size;
	}
	else
	{
		(*adj_merge_size) = (*total_size);
		(*total_size) = 0;
	}
}
