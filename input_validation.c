/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:57:52 by yolee             #+#    #+#             */
/*   Updated: 2022/06/16 01:39:24 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
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

void	insert_index_list(t_list **index_list, t_double_llst *new_node)
{
	if ((*index_list) == NULL)
		(*index_list) = ft_lstnew(new_node);
	else
		insert_new_node(index_list, new_node);
}
