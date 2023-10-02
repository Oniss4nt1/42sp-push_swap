/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:52:05 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/02 14:09:23 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pre_sort_slot(t_stack *stack, int num_slot, int slot_size);

void	sort(t_stack *stack)
{
	if (stack->size_a < 3)
		swap(&stack->head_a, 'a', stack);
	else if (stack->size_a == 3)
		sort_short(stack);
	else if (stack->size_a <= 5)
	{
		pre_sort_slot(stack, 1, stack->size_a);
		sort_medium(stack);
	}
	// else
	// 	sort_long(stack);
}

void	pre_sort_slot(t_stack *stack, int num_slot, int slot_size)
{
	int key_nbr;
	int rotate_flag;
	int values;
	
	rotate_flag = 0;
	key_nbr = stack->size_a * num_slot;	
	values = value_exist(stack->head_a, key_nbr);
	while (values)
	{
		if (stack->head_a->value < key_nbr)
		{
			if (rotate_flag == 1)
				rotate(&stack->head_b, 'b', stack);
			if (stack->head_a->value < key_nbr - (slot_size / 2))
				push_a_to_b(stack);
			else
				push_a_to_b(stack);
		}
		else
		{
			if (rotate_flag == 1)
				reverse_rotate(&stack->head_b, 'b', stack);
			else
				rotate(&stack->head_a, 'a', stack);
				
		}
		values = value_exist(stack->head_a, key_nbr);	
	}
}

