/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:31:44 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 12:48:05 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size_a = 0;
	stack->size_b = 0;
	stack->moves = 0;
	stack->head_a = NULL;
	stack->head_b = NULL;
	return (stack);
}

// t_numbers init_numbers(void)
// {
// 	t_numbers	array;

// 	array.size = 0;
// 	array.num = NULL;
// 	return (array);
// }