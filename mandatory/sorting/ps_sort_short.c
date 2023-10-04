/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:04:26 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/04 16:37:26 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_short(t_stack *stack)
{
	if (stack->size_a == 2)
	{
		if (stack->head_a->value > stack->head_a->next->value)
			swap(&stack->head_a, 'a', stack);
		return ;
	}
	if (stack->size_a < 3 || stack->size_a > 10)
		return ;
	while (stack->size_a > 3)
	{
		move_min_top(stack);
		push_a_to_b(stack);
	}
	sort_three(&stack->head_a, stack->size_a, stack);
	while (stack->size_b > 0)
	{
		push_b_to_a(stack);
		if (stack->head_a->value > stack->head_a->next->value)
			swap(&stack->head_a, 'a', stack);
	}
}
