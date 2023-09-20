/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:40 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/20 18:41:45 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	t_node *first;
	t_node *second;

	if (stack->size_a < 2)
		return ;
	first = stack->head_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->head_a = second;
}

// void	swap_b(t_stack *stack)
// {
// 	t_node *first;
// 	t_node *second;

// 	if (stack->size_b < 2)
// 		return ;
// 	first = stack->head;
// 	second = first->next;
// 	first->next = second->next;
// 	second->next = first;
// 	stack->head = second;
// }

// void swap_swap(t_stack *stack)
// {
// 	swap_a(stack);
// 	swap_b(stack);
// }