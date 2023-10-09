/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_memory_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:43:13 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 15:23:27 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function: free_list
 * -----------------
 * This function is used to free the list. It iterates through the list and frees
 * each node.
 * 
 * @param: *head: pointer to the head of the list.
 * @var: *current: pointer to the current node.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	free_list(t_node *head)
{
	t_node	*current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * Function: free_stack
 * -----------------
 * This function is used to free the list. It iterates through the list and frees
 * each node.
 * 
 * @param: *head: pointer to the head of the list.
 * @var: *current: pointer to the current node.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	free_stack(t_stack *stack)
{
	free_list(stack->head_a);
	free_list(stack->head_b);
	free(stack);
}

/**
 * Function: free_error
 * -----------------
 * This function is used to free in case of error. It frees the list, the array
 * of numbers, the string array and the stack.
 * 
 * @param: *stack: pointer to the stack.
 * @param: *array: pointer to the array of numbers.
 * @param: **str: pointer to the string array.
 * @param: i: index of the string array.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

void	free_error(t_stack *stack, t_numbers *array, char **str, int i)
{
	ft_putstr_fd("Error\n", 2);
	free(str[i]);
	free(str);
	free(array->num);
	free_stack(stack);
	exit(1);
}
