/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:04:26 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/25 19:06:51 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_ten(t_stack *stack)
{
	int i;

	i = 0;
	if (stack->size_a <= 5)
	{
		sort_five(stack);
		return ;
	}
	while (i < stack->size_a - 5)
	{
		move_min_top(stack);
		push_a_to_b(stack);
		i++;
	}
	sort_five(stack);
	while (stack->size_b > 0)
	{
		push_b_to_a(stack);
		if (stack->head_a->value > stack->head_a->next->value)
			rotate(&stack->head_a, 'a', stack);
		
	}
}



// int	median_of_three(t_stack *stack);
// int get_nth_value(t_node *head, int n);

// void	quick_sort(t_stack *a, t_stack *b, int size)
// {
// 	int i;
// 	int pivot;
// 	int pushed;

// 	if (size <= 1)
// 		return ;
// 	i = 0;
// 	pushed = 0;
// 	pivot = median_of_three(a);
// 	while (i < size)
// 	{
// 		if (a->head_a->value < pivot)
// 		{
// 			push_a_to_b(a);
// 			pushed++;
// 		}
// 		else
// 			rotate(&a->head_a, 'a', a);
// 		i++;
// 	}
// 	quick_sort(a, b, size - pushed);
// 	while (pushed)
// 	{
// 		push_b_to_a(a);
// 		if (a->head_a->value > a->head_a->next->value)
// 			swap(&a->head_a, 'a', a);
// 		pushed--;
// 	}
	
// }

// int	median_of_three(t_stack *stack)
// {
// 	int	first;
// 	int middle;
// 	int last;
// 	t_node *temp;

// 	temp = stack->head_a;
// 	first = temp->value;
// 	middle = get_nth_value(temp, stack->size_a / 2);
// 	last = get_nth_value(temp, stack->size_a - 1);

// 	if ((first <= middle && middle <= last) || (last <= middle && middle <= first))
// 		return (middle);

// 	else if ((middle <= first && first <= last) || (last <= first && first <= middle))
// 		return (first);

// 	else
// 		return (last);
// }

// int get_nth_value(t_node *head, int n)
// {
// 	int i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		head = head->next;
// 		i++;
// 	}
// 	return (head->value);
// }
