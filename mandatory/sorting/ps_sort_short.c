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

/**
 * Function: sort_short
 * -----------------
 * This function sorts a list of 3 to 15 numbers. It first moves the minimum
 * number to the top of the list, then pushes it to the stack b, in this way
 * the stack b will be sorted in ascending order. Then it sorts the stack a
 * using the sort_three function, and finally it pushes the numbers from the
 * stack b to the stack a, and if the first two numbers of the stack a are not
 * sorted, it swaps them.
 * 
 * 
 * @param: *stack: pointer to the stack.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

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

/**
 * Function: move_min_top
 * -----------------
 * This function moves the minimum number of the stack a to the top of the
 * stack a. It first finds the minimum number and its position, then if
 * the position is greater than the size of the stack a divided by 2, it
 * rotates the stack a, otherwise it reverse rotates the stack a. This is
 * done in order to minimize the number of operations. 
 * 
 * @param: *stack: pointer to the stack.
 * @var: min: minimum number of the stack a.
 * @var: pos: position of the minimum number of the stack a.
 * @var: *current: pointer to the current node of the stack a.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

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
