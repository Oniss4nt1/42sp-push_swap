/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:24:58 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 15:16:46 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Function: is_sorted
 * -----------------
 * This function checks if the list is sorted. It is always called after
 * a number is added to the list. Basically, it compares the value of the
 * current node with the value of the next node. If the value of the current
 * node is greater than the value of the next node, it returns false. If the
 * list is sorted, it returns true.
 *  
 * @param: *head: pointer to the head of the list.
 *
 * @return: This is a t_bool function, so it returns true or false.
 *
 */

t_bool	is_sorted(t_node *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (is_false);
		head = head->next;
	}
	return (is_true);
}

/**
 * Function: is_duplicate
 * -----------------
 * This function checks if there are duplicate values in the list. It is always
 * called after a number is added to the list. Basically, it compares the value
 * of the current node with the value of the next node. If the value of the
 * current node is equal to the value of the next node, it returns false. If
 * there are no duplicate values, it returns true.
 *  
 * @param: *head: pointer to the head of the list.
 *
 * @return: This is a t_bool function, so it returns true or false.
 *
 */

t_bool	is_duplicate(t_node *head)
{
	t_node	*current;
	t_node	*next_node;

	current = head;
	while (current)
	{
		next_node = current->next;
		while (next_node)
		{
			if (current->value == next_node->value)
			{
				ft_putstr_fd("Error\n", 2);
				return (is_true);
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (is_false);
}
