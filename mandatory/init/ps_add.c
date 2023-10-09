/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:21 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 12:48:43 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Function: add_to_list
 * -----------------
 * Adds a new node to the end of the list.
 * 
 * @param: **head: pointer to the head of the list.
 * @param: value: value to be stored in the new node.
 * @param: *stack: pointer to the stack.
 * @var: *new_node: pointer to the new node.
 * @var: *current: pointer to the current nodek, used to traverse the list.
 * @var: stack->size_a: size of the stack.
 *
 * @return: This is a void function, so it does not return a value.
 *
 */

void	add_to_list(t_node **head, t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = init_node(value);
	if (!*head)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size_a++;
}

/**
 * Function: add_to_head
 * -----------------
 * Adds a new node to the head of the list. This is used when a function
 * move a node from one list to another or when a node is pushed to the top.
 * 
 * @param: **head: pointer to the head of the list.
 * @param: value: value to be stored in the new node.
 * @var: *new_node: pointer to the new node.
 *
 * @return: This is a void function, so it does not return a value.
 *
 */

void	add_to_head(t_node **head, int value)
{
	t_node	*new_node;

	new_node = init_node(value);
	new_node->next = *head;
	*head = new_node;
}
