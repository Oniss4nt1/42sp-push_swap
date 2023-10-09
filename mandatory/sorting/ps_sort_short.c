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

int	find_min(t_node *head);
int	find_distance_top(t_stack *stack, int min);

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
 * stack a. It calls the find_min function to find the minimum number, then
 * it calls the find_distance_top function to find the distance of the minimum
 * number to the top of the stack a. Finally, it rotates or reverse rotates
 * the stack a depending on the distance of the minimum number to the top of
 * the stack a.
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
	int		distance_top;
	int		distance_bottom;

	min = find_min(stack->head_a);
	distance_top = find_distance_top(stack, min);
	distance_bottom = stack->size_a - distance_top;

	while (stack->head_a->value != min)
	{
		if (distance_top <= distance_bottom)
			rotate(&stack->head_a, 'a');
		else 
			reverse_rotate(&stack->head_a, 'a');
	}
}

/**
 * Function: find_min
 * -----------------
 * This function finds the minimum number of the stack a.
 * 
 * @param: *head: pointer to the head of the stack a.
 * @var: min: minimum number of the stack a.
 * @var: *tmp: pointer to the current node of the stack a.
 * 
 * @return: This is a void function, so it does not return a value.
 *
 */

int	find_min(t_node *head)
{
	int	min;
	t_node *current;

	current = head;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

/**
 * Function: find_distance_top
 * -----------------
 * This function finds the distance of the minimum number of the stack a to the
 * top of the stack a. 
 * 
 * @param: *stack: pointer to the stack.
 * @var: min: minimum number of the stack a.
 * 
 * @return: This function returns the distance of the minimum number of the
 * stack a to the top of the stack a.
 *
 */

int	find_distance_top(t_stack *stack, int min)
{
	int		distance;
	t_node *current;

	distance = 0;
	current = stack->head_a;
	while (current->value != min)
	{
		current = current->next;
		distance++;
	}
	return (distance);
}