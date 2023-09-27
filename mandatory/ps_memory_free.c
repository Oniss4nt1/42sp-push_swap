/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_memory_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:43:13 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/27 14:01:04 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_stack(t_stack *stack)
{
	free_list(stack->head_a);
	free_list(stack->head_b);
	free(stack);
}

