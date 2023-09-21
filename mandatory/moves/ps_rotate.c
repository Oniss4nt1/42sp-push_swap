/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:00:10 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/21 17:14:40 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack *stack)
{
	t_node *first;
	t_node *last;

	if (stack->size_a < 2)
		return ;
	first = stack->head_a;
	last = stack->head_a;
	while (last->next)
		last = last->next;
	stack->head_a = first->next;
	first->next = NULL;
	last->next = first;
}

void	rotate_b(t_stack *stack)
{
	t_node *first;
	t_node *last;

	if (stack->size_b < 2)
		return ;
	first = stack->head_b;
	last = stack->head_b;
	while (last->next)
		last = last->next;
	stack->head_b = first->next;
	first->next = NULL;
	last->next = first;
}

void	rotate_rotate(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}