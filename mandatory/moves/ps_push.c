/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:02:04 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/05 14:45:06 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * Function: push_a_to_b
 * -----------------
 * This function pushes the first node of the list a to the top of the list b.
 * For do that, it adds a new node to the head of the list b and then updates
 * the head of the list a, changing it to the next node (aka the second node).
 * It also updates the size of the lists.
 * 
 * @param: *stack: pointer to the stack.
 * @var: *first: pointer to the first node of the list a.
 *
 * @return: This is a void function, so it does not return a value.
 *
 */

void	push_a_to_b(t_stack *stack)
{
	t_node	*first;

	if (!stack->head_a)
		return ;
	first = stack->head_a;
	add_to_head(&stack->head_b, first->value);
	stack->head_a = first->next;
	first->next = NULL;
	free(first);
	stack->size_a--;
	stack->size_b++;
	ft_printf("pb\n");
}

/**
 * Function: push_b_to_a
 * -----------------
 * This function pushes the first node of the list b to the top of the list a.
 * For do that, it adds a new node to the head of the list a and then updates
 * the head of the list b, changing it to the next node (aka the second node).
 * It also updates the size of the lists.
 * 
 * @param: *stack: pointer to the stack.
 * @var: *first: pointer to the first node of the list a.
 *
 * @return: This is a void function, so it does not return a value.
 *
 */

void	push_b_to_a(t_stack *stack)
{
	t_node	*first;

	if (!stack->head_b)
		return ;
	first = stack->head_b;
	add_to_head(&stack->head_a, first->value);
	stack->head_b = first->next;
	first->next = NULL;
	free(first);
	stack->size_a++;
	stack->size_b--;
	ft_printf("pa\n");
}
