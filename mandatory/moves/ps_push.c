/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:02:04 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/25 17:35:35 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_to_b(t_stack *stack)
{
	t_node *first;

	if (!stack->head_a)
		return ;
	first = stack->head_a;
	add_to_head(&stack->head_b, first->value);
	stack->head_a = first->next;
	free(first);
	stack->size_a--;
	stack->size_b++;
	ft_printf("pb\n");
	print_stacks(stack);
}

void	push_b_to_a(t_stack *stack)
{
	t_node *first;

	if (!stack->head_b)
		return ;
	first = stack->head_b;
	add_to_head(&stack->head_a, first->value);
	stack->head_b = first->next;
	free(first);
	stack->size_a++;
	stack->size_b--;
	ft_printf("pa\n");
	print_stacks(stack);
}