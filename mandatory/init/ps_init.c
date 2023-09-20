/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:31:44 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/20 17:39:15 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_node *init_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_stack *init_stack(void)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size_a = 0;
	stack->size_b = 0;
	stack->min_a = 0;
	stack->min_b = 0;
	stack->max_a = 0;
	stack->max_b = 0;
	stack->head_a = NULL;
	stack->head_b = NULL;
	return (stack);
}