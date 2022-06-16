/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_indexing_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:27:21 by yolee             #+#    #+#             */
/*   Updated: 2022/06/17 03:45:59 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_new_node(t_list **index_list, t_double_llst *new_node)
{
	t_list			*iter;
	t_list			*iter_prev;
	t_double_llst	*content;

	content = (t_double_llst *)(*index_list)->content;
	iter = (*index_list);
	iter_prev = (*index_list);
	while (iter != NULL && content->data < new_node->data)
	{
		iter_prev = iter;
		iter = iter->next;
		if (iter != NULL)
			content = (t_double_llst *)iter->content;
	}
	if (iter != NULL && content->data == new_node->data)
		print_error();
	if (iter_prev == iter)
		ft_lstadd_front(index_list, ft_lstnew(new_node));
	else
	{
		iter_prev->next = ft_lstnew(new_node);
		iter_prev->next->next = iter;
	}
}

static int	ft_issign(const char chr)
{
	if (chr == '+' || chr == '-')
		return (1);
	else
		return (0);
}

static int	ft_atoi_exception_handle(const char *str)
{
	long long	conv_num;
	int			sign;
	const char	*iter_ptr;

	sign = 1;
	conv_num = 0;
	iter_ptr = str;
	if (ft_issign(*iter_ptr))
	{
		if ((*iter_ptr) == '-')
			sign = -1;
		iter_ptr++;
	}
	while (ft_isdigit(*iter_ptr))
	{
		conv_num = (conv_num * 10) + ((sign) * ((*iter_ptr) - '0'));
		if (conv_num < -2147483648 || conv_num > 2147483647)
			print_error();
		iter_ptr++;
	}
	return ((int)(conv_num));
}

void	add_to_stack(t_list **index_list,
				t_stack *stack,
				char *num_str)
{
	t_double_llst	*new_node;

	new_node = init_node(ft_atoi_exception_handle(num_str));
	if ((*index_list) == NULL)
		(*index_list) = ft_lstnew(new_node);
	else
		insert_new_node(index_list, new_node);
	push_bottom(stack, new_node);
}
