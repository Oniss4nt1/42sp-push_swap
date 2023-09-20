/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:21 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/20 18:50:14 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Function: add_to_list
 * -----------------
 * This function adds a new node to the end of a circular doubly linked list.
 * If the list is empty, the new node is the head of the list. Otherwise, the
 * new node is added to the end of the list. For add the new node to the end,
 * we have to update the pointers of the last node and the head node. When the
 * new node is added to the end, the next pointer of the last node points to
 * the new node, and the prev pointer of the head node points to the new node.
 * 
 * @param: **head: pointer to the head of the list.
 * @param: value: value to be stored in the new node.
 * @var: *new_node: pointer to the new node.
 * @var: *last_node: pointer to the last node of the list.
 *
 * @return: This is a void function, so it does not return a value.
 *
 */


void add_to_list(t_node **head, t_stack *stack, int value)
{
	t_node *new_node;
	t_node *current;

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
	if (stack->size_a == 1)
	{
		stack->min_a = value;
		stack->max_a = value;
	}
	else
	{
		if (value < stack->min_a)
			stack->min_a = value;
		if (value > stack->max_a)
			stack->max_a = value;
	}
}