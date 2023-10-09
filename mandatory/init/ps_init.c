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

#include "../push_swap.h"

/**
 * Function: init_node
 * -----------------
 * This function initializes a new node. It allocates memory for the node and
 * sets the value to the value passed as argument. It also sets the next node
 * to NULL.
 *  
 * @param: value: value to be stored in the new node.
 * 
 * @return: This is a t_node function, so it returns a pointer to the new node.
 *
 */

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

/**
 * Function: init_stack
 * -----------------
 * This function initializes a new stack. It allocates memory for the stack and
 * sets the size of the stack to 0 and the head of the list to NULL.
 *  
 * @param: void.
 * 
 * @return: This is a t_stack function, so it returns a pointer to the new stack.
 *
 */

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
