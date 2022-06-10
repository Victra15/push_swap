/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:57:52 by yolee             #+#    #+#             */
/*   Updated: 2022/06/05 22:17:13 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(void)
{
	ft_printf("error\n");
	exit(EXIT_FAILURE);
}

void	find_input_error(char *input)
{
	if ((*input) == '\0')
		print_error();
	while ((*input) != '\0')
	{
		if (!ft_isdigit((*input)) && *input != ' ')
			print_error();
		input++;
	}
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
