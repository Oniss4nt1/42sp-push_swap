/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:04:26 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 18:34:01 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_short(t_stack *stack)
{
	if (stack->size_a == 2)
	{
		if (stack->head_a->value > stack->head_a->next->value)
			swap(&stack->head_a, 'a');
		return ;
	}
	if (stack->size_a < 2 || stack->size_a > 15)
		return ;
	while (stack->size_a > 3)
	{
		move_min_top(stack);
		push_a_to_b(stack);
	}
	sort_three(&stack->head_a, stack->size_a);
	while (stack->size_b > 0)
	{
		push_b_to_a(stack);
		if (stack->head_a->value > stack->head_a->next->value)
			swap(&stack->head_a, 'a');
	}
}

void	move_min_top(t_stack *stack)
{
	int		min;
	int		pos;
	t_node	*current;

	current = stack->head_a;
	min = current->value;
	pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			pos++;
		}
		current = current->next;
	}
	if (pos > stack->size_a / 2)
		while (stack->head_a->value != min)
			reverse_rotate(&stack->head_a, 'a');
	else
		while (stack->head_a->value != min)
			rotate(&stack->head_a, 'a');
}
