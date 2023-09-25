/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:42:44 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/25 17:34:10 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_node *head);
void	move_min_top(t_stack *stack);
int find_distance_top(t_node *head, int min);

void	sort_five(t_stack *stack)
{
	int i;

	i = 0;
	if (stack->size_a < 5)
		return ;

	while (i < 2)
	{
		move_min_top(stack);
		push_a_to_b(stack);
		i++;
	}
	sort_three(&stack->head_a, stack->size_a, stack);
	i = 0;
	while (i < 2)
	{
		push_b_to_a(stack);
		if (stack->head_a->value > stack->head_a->next->value)
			swap(&stack->head_a, 'a', stack);
		i++;
	}
	
}

int	find_min(t_node *head)
{
	int	min;
	t_node *tmp;

	tmp = head;
	min = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
	
}

void	move_min_top(t_stack *stack)
{
	int	min;
	int distance_top;
	int distance_bottom;

	min = find_min(stack->head_a);
	distance_top = find_distance_top(stack->head_a, min);
	distance_bottom = stack->size_a - distance_top;

	while (stack->head_a->value != min)
	{
		if (distance_top <= distance_bottom)
			rotate(&stack->head_a, 'a', stack);
		else
			reverse_rotate(&stack->head_a, 'a', stack);
	}
}

int find_distance_top(t_node *head, int min)
{
	int distance;
	t_node *temp;

	distance = 0;
	temp = head;
	while (temp->value != min)
	{
		distance++;
		temp = temp->next;
	}
	return (distance);
}