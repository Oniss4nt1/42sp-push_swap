/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:24:58 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/04 17:25:37 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
				ft_putstr_fd("Error\nDuplicate number\n", 2);
				return (is_true);
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
	return (is_false);
}
