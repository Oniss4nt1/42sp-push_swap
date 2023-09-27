/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:24:11 by brunrodr          #+#    #+#             */
/*   Updated: 2023/09/27 19:18:32 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *copy_stack(t_node *head);
int	get_key_nbr(t_stack *stack_k, int key);

void	sort_medium(t_stack *stack)
{
	t_stack *stack_k;
	int	key_nbr;
	int i;

	i = 1;
	stack_k = copy_stack(stack); // Function to copy stack A to stack K
	merge_sort(&stack_k->head_a); // Function to sort stack K

	while (i <= 4)
	{
		key_nbr = get_key_nbr(stack_k, i); // Function to get the key number
		move_elements(stack, key_nbr); // Function to move numbers less than key number to stack B
	}
	
	while (stack->size_b > 0)
	{
		push_b_to_a(stack);
		if (stack->head_a->value > stack->head_a->next->value)
			swap(&stack->head_a, 'a', stack);
	}
	free_stack(stack_k);	
}

t_stack *copy_stack(t_node *head)
{
	t_node *new_head;
	t_node *current;
	
	new_head = NULL;
	current = head;
	while (current)
	{
		add_to_head(&new_head, current->value);
		current = current->next;
	}
	return (new_head);
}

int	get_key_nbr(t_stack *stack_k, int key)
{
	int i;
	int key_nbr;
	t_node *current;

	i = 1;
	current = stack_k->head_a;
	while (current)
	{
		if (i == stack_k->size_a / 4 * key)
		{
			key_nbr = current->value;
			break ;
		}
		current = current->next;
		i++;		
	}
}

void	move_elements(t_stack *stack, int key_nbr)
{
	int i;

	i = 0;
	while (i < stack->size_a)
	{
		if (stack->head_a->value < key_nbr)
			push_a_to_b(stack);
		else
			rotate(&stack->head_a, 'a', stack);
		i++;
	}

}