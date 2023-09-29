/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_medium_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:27:45 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/29 18:21:09 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_next_nbr(t_node *head, int key_nbr)
{
	int	next_nbr;

	next_nbr = 0;
	while (head)
	{
		if (head->value <= key_nbr && (next_nbr == 0 || head->value <= next_nbr))
			next_nbr = head->value;
		head = head->next;
	}
	return (next_nbr);
}

void	move_nbr_to_top(t_stack *stack, int nbr)
{
	int distance_top;
	int distance_bottom;

	distance_top = find_distance_top(stack->head_a, nbr);	
	distance_bottom = stack->size_a - distance_top;

	while (stack->head_a->value != nbr)
	{
		if (distance_top <= distance_bottom)
			rotate(&stack->head_a, 'a', stack);
		else
			reverse_rotate(&stack->head_a, 'a', stack);
	}
}
