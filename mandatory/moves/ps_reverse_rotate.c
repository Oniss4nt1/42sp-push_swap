/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:07:31 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/21 17:21:49 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_stack *stack)
{
	t_node *last;
	t_node *penultimate;

	if (stack->size_a < 2)
		return ;
	penultimate = NULL;
	last = stack->head_a;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
 	last->next = stack->head_a;
	stack->head_a = last;
	
}

void	reverse_rotate_b(t_stack *stack)
{
	t_node *last;
	t_node *penultimate;

	if (stack->size_b < 2)
		return ;
	penultimate = NULL;
	last = stack->head_b;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
	last->next = stack->head_b;
	stack->head_b = last;
}

void	reverse_rr(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}