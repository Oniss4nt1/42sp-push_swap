/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_medium_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:27:45 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/04 17:12:16 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_next_nbr(t_node *head, int key_nbr)
{
	t_node	*current;

	current = head;
	while (current)
	{
		if (current->value < key_nbr)
			return (current->value);
		current = current->next;
	}
	return (0);
}

int	get_index(t_node *head, int value)
{
	int		index;
	t_node	*current;

	index = 0;
	current = head;
	while (current)
	{
		if (current->value == value)
			return (value);
		index++;
		current = current->next;
	}
	return (-1);
}

void	move_nbr_to_top(t_stack *stack, int next_nbr)
{
	int	index;

	index = get_index(stack->head_a, next_nbr);
	if (index < stack->size_a / 2)
	{
		while (stack->head_a->value != next_nbr)
			rotate(&stack->head_a, 'a', stack);
	}
	else
	{
		while (stack->head_a->value != next_nbr)
			reverse_rotate(&stack->head_a, 'a', stack);
	}
}
