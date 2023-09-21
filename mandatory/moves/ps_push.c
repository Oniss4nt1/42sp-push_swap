/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:02:04 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/21 14:59:21 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_stack *stack)
{
	t_node *first;

	if (stack->size_b < 1)
		return ;

	first = stack->head_b;
	add_to_head(&stack->head_a, first->value);
	stack->head_b = first->next;
	free(first);
	stack->size_a++;
	stack->size_b--;
}

void	push_b(t_stack *stack)
{
	t_node *first;

	if (stack->size_a < 1)
		return ;

	first = stack->head_a;
	add_to_head(&stack->head_b, first->value);
	stack->head_a = first->next;
	free(first);
	stack->size_a--;
	stack->size_b++;
}
