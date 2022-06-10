/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:13:04 by yolee             #+#    #+#             */
/*   Updated: 2022/06/02 17:44:12 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double_llst	*init_node(int _data)
{
	t_double_llst	*new;

	new = (t_double_llst *)malloc(sizeof(t_double_llst));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->data = _data;
	new->prev = NULL;
	return (new);
}

t_stack	*init_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->cnt = 0;
	new->top = NULL;
	new->bottom = NULL;
	return (new);
}

static void	stack_indexing(t_list *index_list)
{
	t_list			*temp;
	t_double_llst	*content;
	int				index;

	index = 0;
	while (index_list != NULL)
	{
		content = (t_double_llst *)index_list->content;
		content->index = index;
		index++;
		temp = index_list;
		index_list = index_list->next;
		free(temp);
	}
}

static void	set_stack(t_stack *stack, int argc, char **argv)
{
	int				loop;
	char			**input_set;
	t_list			*index_list;
	t_double_llst	*new_node;

	loop = 1;
	index_list = NULL;
	while (loop < argc)
	{
		find_input_error(argv[loop]);
		input_set = ft_split(argv[loop], ' ');
		while ((*input_set) != NULL)
		{
			new_node = init_node(ft_atoi(*input_set));
			insert_index_list(&index_list, new_node);
			push_bottom(stack, new_node);
			input_set++;
		}
		loop++;
	}
	stack_indexing(index_list);
}

t_stacks	*init_stacks(int argc, char **argv)
{
	t_stacks	*new;

	new = (t_stacks *)malloc(sizeof(t_stacks));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->a = init_stack();
	new->b = init_stack();
	set_stack(new->a, argc, argv);
	return (new);
}
